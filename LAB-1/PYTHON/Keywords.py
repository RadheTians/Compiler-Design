
def keyword(s):
    temp = []
    keys = ["asm", "else", "new", "this", "auto", "enum", "operator", "throw", "bool",
              "explicit", "private", "true", "break", "export", "protected", "try",
              "case", "extern", "public", "typedef", "catch", "false", "register",
              "typeid", "char", "float", "reinterpret_cast", "typename", "class",
              "for", "return", "union", "const", "friend", "short", "unsigned",
              "const_cast", "goto", "signed", "using", "continue", "if", "sizeof",
              "virtual", "default", "inline", "static", "void", "delete", "int",
              "static_cast", "volatile""do", "long", "struct", "wchar_t",
              "double", "mutable", "switch", "while", "dynamic_cast", "namespace", "template", "include", "iostream",
              "std", "printf"]
    for i in keys :
        if s.find(i) != -1 :
            temp.append(i)

    return temp