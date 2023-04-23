from typing import List, Dict, Tuple
from .arg_info import ArgInfo 
from nodejs_opencv_generator.utils import find_argument_class_info 
from nodejs_opencv_generator.utils import handle_ptr, forbidden_arg_types, ignored_arg_types

class FuncVariant(object):
    def __init__(self, namespace: str, classname: str, name: str, decl: List[str], isconstructor: bool, known_classes: Dict[str, str], isphantom: bool = False):
        self.name: str = name
        self.wname: str = name
        self.isconstructor: bool = isconstructor
        self.isphantom: bool = isphantom

        self.docstring: str = decl[5]

        self.rettype: str = handle_ptr(decl[1])
        
        if self.rettype == "void":
            self.rettype = ""
        self.args: List[ArgInfo] = []
        self.array_counters: Dict[str, List[str]] = {}
        for arg_decl in decl[3]:
            assert len(arg_decl) == 4, \
                'ArgInfo contract is violated. Arg declaration should contain:' \
                '"arg_type", "name", "default_value", "modifiers". '\
                'Got tuple: {}'.format(arg_decl)

            ainfo = ArgInfo(atype=arg_decl[0], name=arg_decl[1],
                            default_value=arg_decl[2], modifiers=arg_decl[3])
            if ainfo.isarray and not ainfo.arraycvt:
                c = ainfo.arraylen
                c_arrlist = self.array_counters.get(c, [])
                if c_arrlist:
                    c_arrlist.append(ainfo.name)
                else:
                    self.array_counters[c] = [ainfo.name]
            self.args.append(ainfo)
        self.init_pyproto(namespace, classname, known_classes)
    
    def init_pyproto(self, namespace: str, classname: str, known_classes: Dict[str, str]) -> None:
        # string representation of argument list, with '[', ']' symbols denoting optional arguments, e.g.
        # "src1, src2[, dst[, mask]]" for cv.add
        argstr = ""

        # list of all input arguments of the Python function, with the argument numbers:
        #    [("src1", 0), ("src2", 1), ("dst", 2), ("mask", 3)]
        # we keep an argument number to find the respective argument quickly, because
        # some of the arguments of C function may not present in the Python function (such as array counters)
        # or even go in a different order ("heavy" output parameters of the C function
        # become the first optional input parameters of the Python function, and thus they are placed right after
        # non-optional input parameters)
        arglist: List[Tuple[str, int]] = []

        # the list of "heavy" output parameters. Heavy parameters are the parameters
        # that can be expensive to allocate each time, such as vectors and matrices (see isbig).
        outarr_list: List[Tuple[str, int]] = []

        # the list of output parameters. Also includes input/output parameters.
        outlist: List[Tuple[str, int]] = []

        firstoptarg = 1000000

        # Check if there is params structure in arguments
        arguments: List[ArgInfo] = []
        for arg in self.args:
            arg_class_info = find_argument_class_info(
                arg.tp, namespace, classname, known_classes
            )
            # If argument refers to the 'named arguments' structure - instead of
            # the argument put its properties
            if arg_class_info is not None and arg_class_info.is_parameters:
                for prop in arg_class_info.props:
                    # Convert property to ArgIfno and mark that argument is
                    # a part of the parameters structure:
                    arguments.append(
                        ArgInfo(prop.tp, prop.name, prop.default_value,
                                enclosing_arg=arg)
                    )
            else:
                arguments.append(arg)
        # Prevent names duplication after named arguments are merged
        # to the main arguments list
        argument_names = tuple(arg.name for arg in arguments)
        assert len(set(argument_names)) == len(argument_names), \
            "Duplicate arguments with names '{}' in function '{}'. "\
            "Please, check named arguments used in function interface".format(
                argument_names, self.name
            )

        self.args = arguments

        for argno, a in enumerate(self.args):
            if a.name in self.array_counters:
                continue
            assert a.tp not in forbidden_arg_types, \
                'Forbidden type "{}" for argument "{}" in "{}" ("{}")'.format(
                    a.tp, a.name, self.name, self.classname
                )

            if a.tp in ignored_arg_types:
                continue
            if a.returnarg:
                outlist.append((a.name, argno))
            if (not a.inputarg) and a.isbig():
                outarr_list.append((a.name, argno))
                continue
            if not a.inputarg:
                continue
            if not a.defval:
                arglist.append((a.name, argno))
            else:
                firstoptarg = min(firstoptarg, len(arglist))
                # if there are some array output parameters before the first default parameter, they
                # are added as optional parameters before the first optional parameter
                if outarr_list:
                    arglist += outarr_list
                    outarr_list = []
                arglist.append((a.name, argno))

        if outarr_list:
            firstoptarg = min(firstoptarg, len(arglist))
            arglist += outarr_list
        firstoptarg = min(firstoptarg, len(arglist))

        noptargs = len(arglist) - firstoptarg
        argnamelist = [self.args[argno].export_name for _, argno in arglist]
        argstr = ", ".join(argnamelist[:firstoptarg])
        argstr = "[, ".join([argstr] + argnamelist[firstoptarg:])
        argstr += "]" * noptargs
        if self.rettype:
            outlist = [("retval", -1)] + outlist
        elif self.isconstructor:
            assert outlist == []
            outlist = [("self", -1)]
        if self.isconstructor:
            if classname.startswith("Cv"):
                classname = classname[2:]
            outstr = "<%s object>" % (classname,)
        elif outlist:
            outstr = ", ".join([o[0] for o in outlist])
        else:
            outstr = "None"

        self.py_arg_str = argstr
        self.py_return_str = outstr
        self.py_prototype = "%s(%s) -> %s" % (self.wname, argstr, outstr)
        self.py_noptargs = noptargs
        self.py_arglist = arglist
        for _, argno in arglist:
            self.args[argno].py_inputarg = True
        for _, argno in outlist:
            if argno >= 0:
                self.args[argno].py_outputarg = True
        self.py_outlist = outlist
