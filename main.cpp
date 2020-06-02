using namespace std;
#include "Field_Z.h"
#include "polinominal.h"
const size_t mem_block = 40 + 1;
int main(int args, char*argv[]){
    char file_name[40 + 1];
    cin.getline(file_name, mem_block);/*"../test.txt"*/
    fstream file;
    file.open(/*argv[1]*/file_name, ios_base::out | ios_base::in);
    DataGetter data(file);
    bool f = data.processing();
    if(!f){
        return 1;
    }
    LagrangePolinom result(std::move(data.getData()), data.p, data.a);
    result.calculation();
    return 0;
}