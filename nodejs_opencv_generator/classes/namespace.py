from typing import Dict, TYPE_CHECKING
if TYPE_CHECKING:
    from func_info import FuncInfo

class Namespace(object):
    def __init__(self):
        self.funcs: list[tuple[str, FuncInfo]] = {}
        self.consts: Dict[str, str] = {}