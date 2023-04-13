from nodejs_opencv_generator.python_reserved_keywords import python_reserved_keywords 
from typing import List

class ClassProp(object):
    def __init__(self, decl: List[str]):
        self.tp: str = decl[0].replace("*", "_ptr")
        self.name: str = decl[1]
        self.default_value: str = decl[2]
        self.readonly: bool = True
        if "/RW" in decl[3]:
            self.readonly = False

    @property
    def export_name(self) -> str:
        if self.name in python_reserved_keywords:
            return self.name + "_"
        return self.name
