from nodejs_opencv_generator.python_reserved_keywords import python_reserved_keywords 

class ClassProp(object):
    def __init__(self, decl):
        self.tp = decl[0].replace("*", "_ptr")
        self.name = decl[1]
        self.default_value = decl[2]
        self.readonly = True
        if "/RW" in decl[3]:
            self.readonly = False

    @property
    def export_name(self):
        if self.name in python_reserved_keywords:
            return self.name + "_"
        return self.name
