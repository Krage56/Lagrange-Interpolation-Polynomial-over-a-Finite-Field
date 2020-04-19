//
// Created by krage56 on 28.03.2020.
//
using namespace std;
#include "Field_Z.h"
#include "polinominal.h"

int main(int args, char*argv[]){
    size_t N = 0, p = 0;
    long a = 0;
    //char file_name[mem_block];
    //cin.getline(file_name, mem_block);/*"../test.txt"*/
    fstream file;
    file.open(argv[1]/*file_name*/, ios_base::out | ios_base::in);
    vector<vector<Field_Z>> data;//{x, y}
    if(!processing(&file, N, p, a, data)){
        cout << "The program can`t open the file" << endl;
        return 1;
    }
    calculation(data, p, a);
    file.close();

    return 0;
}