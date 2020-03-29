//
// Created by krage56 on 28.03.2020.
//

#ifndef CNK_POLINOMINAL_H
#define CNK_POLINOMINAL_H
#pragma once


#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <typeinfo>
#include "Field_Z.h"

const size_t mem_block = 40 + 1;
void return_in_pos(std::fstream *file, bool pos);
bool is_empty_file(std::fstream *file);
bool processing(std::fstream*, size_t &, size_t &, long &, std::vector<std::vector<Field_Z>> &);
void generateSet(std::vector<size_t> &, size_t, size_t);



#endif //CNK_POLINOMINAL_H
