replaces_code = [
    ("PR", "R0"),
    (""),
]

str_sign = [
    "'",
    '"'
]

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
        code[i] = code[i].split(" ")



        extens = []
        tmpl = []
        tmp = False
        for j in range(len(code[i])):
            if code[i][j] != "":
                if code[i][j][0] in str_sign and code[i][j][-1] in str_sign:
                    extens.append([j])
                    continue
                if code[i][j][0] in str_sign or code[i][j][-1] in str_sign:
                    if tmp:
                        tmpl.append(j)
                        extens.append(tmpl)
                        tmpl = []
                    tmp = not(tmp)
            if tmp:
                tmpl.append(j)
        del tmpl, tmp
        for j in extens:
            tmpl = []
            tmpcl = []
            for z in j:
                tmpl.append(code[i][z])
                tmpcl.append(z)
            del tmpcl[0]
            code[i][j[0]] = " ".join(tmpl)
            tmpcl.sort(reverse=True)
            for z in tmpcl:
                del code[i][z]
        del tmpl, tmpcl, z



        l = []
        for j in range(len(code[i])):
            if code[i][j] == "":
                l.append(j)
        l.sort(reverse=True)
        for j in l:
            del code[i][j]
    return(code)

def tobytes(code:list) -> bytearray:
    s = ""
    for i in code:
        for j in range(len(i)):
            i[j] = i[j].lower()
        match code[0]:
            case "mov":
                pass

""" def compile(code:str) -> bytearray:
    pass """
