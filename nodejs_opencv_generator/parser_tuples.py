from typing import Optional, Any, List, Tuple

class FuncDecl(tuple):
    __slots__ = ()

    def __new__(cls, name: str, retCType: Optional[str], modifiers: List[str], argumentsList: List[Any], originalRetType: Optional[str], docstring: Optional[str]):
        return tuple.__new__(cls, (name, retCType, modifiers, argumentsList, originalRetType, docstring))
    @property
    def name(self) -> str:
        return self[0]
    @name.setter
    def name(self, value: str) -> None:
        self = self._replace(0, value)
    @property
    def retCType(self) -> Optional[str]:
        return self[1]
    @retCType.setter
    def retCType(self, value: Optional[str]) -> None:
        self = self._replace(1, value)
    @property
    def modifiers(self) -> List[str]:
        return self[2]
    @modifiers.setter
    def modifiers(self, value: List[str]) -> None:
        self = self._replace(2, value)
    @property
    def argumentsList(self) -> List[Any]:
        return self[3]
    @argumentsList.setter
    def argumentsList(self, value: List[Any]) -> None:
        self = self._replace(3, value)
    @property
    def originalRetType(self) -> Optional[str]:
        return self[4]
    @originalRetType.setter
    def originalRetType(self, value: Optional[str]) -> None:
        self = self._replace(4, value)
    @property
    def docstring(self) -> Optional[str]:
        return self[5]
    @docstring.setter
    def docstring(self, value: Optional[str]) -> None:
        self = self._replace(5, value)
    def _replace(self, index: int, value: Any) -> 'FuncDecl':
        new_values = list(self)
        new_values[index] = value
        return FuncDecl(*new_values)

class BlockStack(tuple):
    __slots__ = ()
    def __new__(cls, blockType: str, blockName: str, processFlag: bool, publicSection: bool, classDecl: Optional[List[FuncDecl]]):
        return tuple.__new__(cls, (blockType, blockName, processFlag, publicSection, classDecl))
    @property
    def blockType(self) -> str:
        return self[0]
    @blockType.setter
    def blockType(self, value: str) -> None:
        self = self._replace(0, value)
    @property
    def blockName(self) -> str:
        return self[1]
    @blockName.setter
    def blockName(self, value: str) -> None:
        self = self._replace(1, value)
    @property
    def processFlag(self) -> bool:
        return self[2]
    @processFlag.setter
    def processFlag(self, value: bool) -> None:
        self = self._replace(2, value)
    @property
    def publicSection(self) -> bool:
        return self[3]
    @publicSection.setter
    def publicSection(self, value: bool) -> None:
        self = self._replace(3, value)
    @property
    def classDecl(self) -> Optional[List[FuncDecl]]:
        return self[4]
    @classDecl.setter
    def classDecl(self, value: Optional[List[FuncDecl]]) -> None:
        self = self._replace(4, value)
    def _replace(self, index: int, value: Any) -> 'BlockStack':
        new_values = list(self)
        new_values[index] = value
        return BlockStack(*new_values)

