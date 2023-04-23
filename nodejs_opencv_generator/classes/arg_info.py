
from nodejs_opencv_generator.python_reserved_keywords import python_reserved_keywords 
from nodejs_opencv_generator.utils import handle_ptr 

class ArgInfo(object):
    def __init__(self, atype, name, default_value, modifiers=(),
                 enclosing_arg=None):
        # type: (ArgInfo, str, str, str, tuple[str, ...], ArgInfo | None) -> None
        self.tp = handle_ptr(atype)
        self.name = name
        self.defval = default_value
        self._modifiers = tuple(modifiers)
        self.isarray = False
        self.is_smart_ptr: bool = self.tp.startswith('Ptr<')  # FIXIT: handle through modifiers - need to modify parser
        self.arraylen: str | None = None
        self.arraycvt: str | None = None
        for m in self._modifiers:
            if m.startswith("/A"):
                self.isarray = True
                self.arraylen = m[2:].strip()
            elif m.startswith("/CA"):
                self.isarray = True
                self.arraycvt = m[2:].strip()
        self.py_inputarg = False
        self.py_outputarg = False
        self.enclosing_arg: ArgInfo | None = enclosing_arg

    def __str__(self):
        return 'ArgInfo("{}", tp="{}", default="{}", in={}, out={})'.format(
            self.name, self.tp, self.defval, self.inputarg,
            self.outputarg
        )

    def __repr__(self) -> str:
        return str(self)

    @property
    def export_name(self) -> str:
        if self.name in python_reserved_keywords:
            return self.name + '_'
        return self.name

    @property
    def inputarg(self) -> bool:
        return '/O' not in self._modifiers

    @property
    def outputarg(self) -> bool:
        return '/O' in self._modifiers or '/IO' in self._modifiers

    @property
    def returnarg(self) -> bool:
        return self.outputarg

    @property
    def isrvalueref(self) -> bool:
        return '/RRef' in self._modifiers

    @property
    def full_name(self) -> str:
        if self.enclosing_arg is None:
            return self.name
        return self.enclosing_arg.name + '.' + self.name

    def isbig(self) -> bool:
        return self.tp in ["Mat", "vector_Mat", "cuda::GpuMat", "GpuMat", "vector_GpuMat", "UMat", "vector_UMat"] # or self.tp.startswith("vector")

    def crepr(self) -> str:
        return "ArgInfo(\"%s\", %d)" % (self.name, self.outputarg)