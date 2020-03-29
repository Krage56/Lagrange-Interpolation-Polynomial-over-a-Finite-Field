//
// Created by krage56 on 29.03.2020.
//
using namespace std;
#include "polinominal.h"

void return_in_pos(fstream *file, bool pos){
    file->clear();
    pos ? file->seekg(0, ios_base::beg): file->seekg(0, ios_base::end);
}
bool is_empty_file(fstream *file){
    long file_size;
    file->seekg(0, ios::end);
    file_size = file->tellg();
    return (file_size == 0);
}

bool processing(fstream *file, size_t &N, size_t &p, long &a, vector<vector<Field_Z>> &vec){
    if(!file->is_open()) return false;
    const size_t param_quant = 3;
    return_in_pos(file, true);//Вернуться к началу файла
    char buf[mem_block];
    for(int i = 0; i < param_quant; ++i){
        file->getline(buf, mem_block,i < param_quant - 1 ? ' ': '\n');
        switch (i){
            case 0:{
                p = atoi(buf);
                break;
            }
            case 1:{
                a = atoi(buf);
                break;
            }
            case 2:{
                N = atoi(buf);
                break;
            }
        }
    }

    memset(buf, 0, sizeof(char) * mem_block);
    vector<Field_Z> tmp_vec(2);
    for(int i = 0; i < N; ++i){
        for(short j = 0; j < 2; ++j){
            file->getline(buf, mem_block,j ? '\n': ' ');
            tmp_vec[j] = Field_Z(p, atoi(buf));
        }
        vec.push_back(tmp_vec);
    }
    return true;
}

void generateSet(std::vector<size_t> &vec, size_t except, size_t n) {
    size_t i = 0;
    vec.clear();
    while(i != except){
        vec.push_back(i);
        ++i;
    }
    ++i;
    while(i < n){
        vec.push_back(i);
        ++i;
    }

}


