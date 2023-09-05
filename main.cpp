#include <iostream>
#include <fstream>
#include "cvm/cvm.hpp"
using namespace std;

int main(int args, char * argv[]){
    if(args > 0){
        for(int i = 0; i<args; i++){
            ifstream f;
            f.open(argv[i], ios::in | ios::binary);
            if(f.is_open() == false){
                cout << "错误: 打开文件: \"" << argv[i] << "\" 时失败!" << endl;
                continue;
            }
        }
    }
    else{
        cout << "错误: 没有参数" << endl;
    }
    return(0);
}
