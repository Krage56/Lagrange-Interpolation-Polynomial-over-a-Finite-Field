#pragma once
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <typeinfo>
#include "Field_Z.h"
using  namespace std;
// Created by krage56 on 28.03.2020.
class DataGetter{
public:
    DataGetter(fstream &file);
    ~DataGetter();
    size_t N;
    size_t p;
    long a;
    bool processing();
    std::vector<std::vector<Field_Z>> getData()const{ return _data;};
private:
    void return_in_pos(bool pos);
    bool is_empty_file();

    std::vector<std::vector<Field_Z>> _data;
    fstream *_file;
    const size_t mem_block = 40 + 1;

};
class LagrangePolinom{
public:
    LagrangePolinom(std::vector<std::vector<Field_Z>>&& data, size_t base, long point_x);
    ~LagrangePolinom() = default;

    void calculation();
private:
    std::vector<std::vector<Field_Z>> _data;
    size_t _base;
    long _point_x;
};

