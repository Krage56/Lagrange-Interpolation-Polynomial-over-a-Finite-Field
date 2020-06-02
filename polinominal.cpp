#include "polinominal.h"
#include "Field_Z.h"
using namespace std;

void DataGetter::return_in_pos(bool pos){
    _file->clear();
    pos ? _file->seekg(0, ios_base::beg): _file->seekg(0, ios_base::end);
}
bool DataGetter::is_empty_file(){
    long file_size;
    _file->seekg(0, ios::end);
    file_size = _file->tellg();
    return (file_size == 0);
}

bool DataGetter::processing(){
    if(!_file->is_open()) return false;
    const size_t param_quant = 3;
    return_in_pos(true);//Вернуться к началу файла
    char buf[mem_block];
    for(int i = 0; i < param_quant; ++i){
        _file->getline(buf, mem_block,i < param_quant - 1 ? ' ': '\n');
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
            _file->getline(buf, mem_block,j ? '\n': ' ');
            tmp_vec[j] = Field_Z(p, atoi(buf));
        }
        _data.push_back(tmp_vec);
    }
    return true;
}

void LagrangePolinom::calculation() {
    Field_Z lagrange_pol(_base, 0);
    Field_Z basics_pol(_base, 0);
    Field_Z x(_base, _point_x);
    for (size_t i = 0; i < _data.size(); i++){
        basics_pol = 1;
        for (size_t j = 0; j < _data.size(); j++){
            if (j == i) continue;
            basics_pol *= (x - _data[j][0])/(_data[i][0] - _data[j][0]);
        }
        lagrange_pol += basics_pol*_data[i][1];
    }
    lagrange_pol.normalize();
    ofstream answer;
    answer.open("./answer.txt");
    answer << lagrange_pol << "\n";
    answer.close();
}

DataGetter::DataGetter(fstream &file) {
    _file = &file;
}

DataGetter::~DataGetter() {
    _file->close();
}

LagrangePolinom::LagrangePolinom
(std::vector<std::vector<Field_Z>> &&data, size_t base, long point_x)
{
    _data = data;
    _base = base;
    _point_x = point_x;
}
