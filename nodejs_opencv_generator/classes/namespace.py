from typing import Dict, Union, TYPE_CHECKING
if TYPE_CHECKING:
    from .func_info import FuncInfo
    from .class_info import ClassInfo

class Namespace(object):
    def __init__(self: 'Namespace'):
        self.funcs: Dict[str, Union[ClassInfo, FuncInfo]] = {}
        self.consts: Dict[str, str] = {}

