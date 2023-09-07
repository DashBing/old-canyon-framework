#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include "../cvm/cvm.hpp"
using namespace std;

#define cases(c) case c: mem_reallen *= 1024;

int main(int args, char * argv[]){
    if(args > 0){
        cout << "请输入内存大小:";
        UINT64 mem_reallen;
        cin >> mem_reallen;
        char mode;
        cout << "内存计量单位(支持K, M, G, T, P, E, 输入D或其他非此范围的字母则使用字节计量):";
        cin >> mode;
        mode = toupper(mode);
        switch (mode){
            cases('E') cases('P') cases('T') cases('G') cases('M')
            case 'K':
                mem_reallen *= 1024;
                break;
            default:
                break;
        }
        char * mem = (char *)calloc(mem_reallen, sizeof(char));
        UINT64 memlen = 0;
        for(int i = 0; i<args; i++){
            ifstream f;
            command tmp = {};
            f.open(argv[i], ios::in | ios::binary);
            if(f.is_open() == false){
                cout << "错误: 打开文件: \"" << argv[i] << "\" 时失败!" << endl;
                continue;
            }
            while (f.read((char *)&tmp, sizeof(command))){
                //mem = (char *)realloc(mem, memlen + sizeof(command));
                for (UINT64 j = 0; j<sizeof(command); j++){
                    mem[memlen + j] = ((char *)&tmp)[j];
                }
                memlen += sizeof(command);
            }
        }
        VM mainvm;
        free(mem);
    }
    else{
        cout << "错误: 没有参数" << endl;
    }
    return(0);
}

#undef cases
