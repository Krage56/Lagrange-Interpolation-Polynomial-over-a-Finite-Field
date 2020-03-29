//
// Created by krage56 on 28.03.2020.
//
using namespace std;
#include "getSubsets.h"
#include "Field_Z.h"
#include "polinominal.h"


int main(){
    size_t N = 0, p = 0;
    long a = 0;
    char file_name[mem_block];
    cin.getline(file_name, mem_block);/*"../test.txt"*/
    fstream file;
    file.open(file_name, ios_base::out | ios_base::in);
    vector<vector<Field_Z>> data;//{x, y}
    if(!processing(&file, N, p, a, data)){
        cout << "The program can`t open the file" << endl;
        return 1;
    }

    vector <Field_Z> set(1)/*это костыль*/, coefficients, tmp_coefficients;

    //инициализация
    Field_Z tmp_obj(p, 0);
    for(size_t i = 0; i < N; ++i){
        coefficients.push_back(tmp_obj);
        tmp_coefficients.push_back(tmp_obj);
    }
    vector<size_t>ex_i;
    vector<vector<size_t>>set_ind(0);
    tmp_obj = 1;
    Field_Z denominator(p, 1);
    for(size_t i = 0; i < N; ++i){
        //сгенерируем выборку без i-го корня
        generateSet(ex_i, i, N);
        //вычисляем коэф-ы в числителе
        for(size_t j = 0; j < N; ++j){
            if (j == 0) tmp_coefficients[j] = 1;//для первого коэф-а
            set_ind = getSubsets(ex_i, j);//по т.Виета получим коэф-т при t^(N-j-1)
            //суммируем и приводим коэф-ты

            for(size_t k = 0; k < set_ind.size(); ++k ){
                //приводим коэф-ты
                tmp_obj = 1;
                for(size_t wk = 0; wk < j; ++wk){
                    tmp_obj *= data[set_ind[k][wk]][0];
                }
                tmp_coefficients[j] += tmp_obj;//суммируем
            }
            //ставим нужный знак перед коэф-ом - по т. Виета
            j % 2 ? tmp_coefficients[j] *= (-1) : tmp_coefficients[j] *= (1);

            //tmp_coefficients[j] *= data[i][1];
        }
        //вычислим знаменатель
        for(int j = 0; j < data.size(); j++){
            if(j != i) denominator *= (data[i][0] - data[j][0]);
        }
        //сложим свежеполученные коэф-ы с соотв-ими других дробей
        for(int j = 0; j < N; ++j){
            coefficients[j] += ((tmp_coefficients[j] / denominator) * data[i][1]);
            tmp_coefficients[j] = 0;//сразу освободим промежуточный массив
        }
        //очистим временные переменные для новой итерации
        //tmp_obj = 1;
        denominator = 1;
    }
    cout << N << " " << p << " " << a << endl;
    for(int i = 0; i < N; ++i){
        cout << coefficients[i] << endl;
    }
    file.close();
    return 0;
}