from typing import TYPE_CHECKING, Dict

if TYPE_CHECKING:
    from .classes.class_info import ClassInfo

import re

ignored_arg_types = ["RNG*"]
forbidden_arg_types = ["void*"]

class FormatStrings:
    string = 's'
    unsigned_char = 'b'
    short_int = 'h'
    int = 'i'
    unsigned_int = 'I'
    long = 'l'
    unsigned_long = 'k'
    long_long = 'L'
    unsigned_long_long = 'K'
    size_t = 'n'
    float = 'f'
    double = 'd'
    object = 'O'

pass_by_val_types = ["Point*", "Point2f*", "Rect*", "String*", "double*", "float*", "int*"]

def handle_ptr(tp):
    if tp.startswith('Ptr_'):
        tp = 'Ptr<' + "::".join(tp.split('_')[1:]) + '>'
    return tp

def get_type_format_string(arg_type_info):
    if arg_type_info.strict_conversion:
        return FormatStrings.object
    else:
        return arg_type_info.format_str


def find_argument_class_info(argument_type, function_namespace, function_class_name, known_classes):
    # type: (str, str, str, dict[str, ClassInfo]) -> ClassInfo | None
    """Tries to find corresponding class info for the provided argument type

    Args:
        argument_type (str): Function argument type
        function_namespace (str): Namespace of the function declaration
        function_class_name (str): Name of the class if function is a method of class
        known_classes (dict[str, ClassInfo]): Mapping between string class
            identifier and ClassInfo struct.

    Returns:
        Optional[ClassInfo]: class info struct if the provided argument type
            refers to a known C++ class, None otherwise.
    """

    possible_classes = tuple(filter(lambda cls: cls.endswith(argument_type), known_classes))
    # If argument type is not a known class - just skip it
    if not possible_classes:
        return None
    if len(possible_classes) == 1:
        return known_classes[possible_classes[0]]

    # If there is more than 1 matched class, try to select the most probable one
    # Look for a matched class name in different scope, starting from the
    # narrowest one

    # First try to find argument inside class scope of the function (if any)
    if function_class_name:
        type_to_match = function_class_name + '_' + argument_type
        if type_to_match in possible_classes:
            return known_classes[type_to_match]
    else:
        type_to_match = argument_type

    # Trying to find argument type in the namespace of the function
    type_to_match = '{}_{}'.format(
        function_namespace.lstrip('cv.').replace('.', '_'), type_to_match
    )
    if type_to_match in possible_classes:
        return known_classes[type_to_match]

    # Try to find argument name as is
    if argument_type in possible_classes:
        return known_classes[argument_type]

    # NOTE: parser is broken - some classes might not be visible, depending on
    # the order of parsed headers.
    # print("[WARNING] Can't select an appropriate class for argument: '",
    #       argument_type, "'. Possible matches: '", possible_classes, "'")
    return None

def normalize_class_name(name):
    return re.sub(r"^cv\.", "", name).replace(".", "_")

