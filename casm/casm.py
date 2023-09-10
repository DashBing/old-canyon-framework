def precom(code:str) -> list[list[str, ], ]:  # 按照换行分隔 并删除注释 再进行语句分隔
    code.replace("\r", "\n")
    code = code.split("\n")
    l = []
    for i in range(len(code)):
        code[i] = code[i].split(";")[0]
        if code[i] == "":
            l.append(i)
    for i in l:
        del code[i]
    for i in range(len(code)):
        l = []
        code[i] = code[i].split(" ")
        for j in range(len(code[i])):
            if code[i][j] == "":
                l.append(j)
        for j in l:
            del code[i][j]
    return(code)

def tobytes(code:list) -> bytearray:
    s = ""
    for i in code:
        for j in range(len(i)):
            i[j] = i[j].upper()
        match code[0]:
            case "MOV":
                pass

def compile(code:str) -> bytearray:
    pass
