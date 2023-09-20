from sys import argv
from casm import *

def main(args:list):
    a = ""
    argt = args
    del argt[-1]
    for i in argt:
        with open(i, "r") as f:
            r = f.read()
            r = compile(r)
            a = a + r

if __name__ == "__main__":
    print(precom(input()))
    #del argv[0]
    #main(argv)
