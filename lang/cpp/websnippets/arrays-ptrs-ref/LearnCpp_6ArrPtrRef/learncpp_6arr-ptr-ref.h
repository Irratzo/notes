/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   learncpp_6arr-ptr-ref.h
 * Author: johannesw
 *
 * Created on 10. Juli 2017, 10:56
 */

#ifndef LEARNCPP_6ARR_PTR_REF_H
#define LEARNCPP_6ARR_PTR_REF_H

#if defined(_WIN32) || (defined(__APPLE__) && defined(__MACH__))
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional> //for Lambdas
#include <memory>
#include <type_traits>
#include <initializer_list> //for AutoDeclType
//#include <typeinfo> //for typeid()
#else
#include <bits/stdc++.h>
//#include <typeinfo> //for typeid()
#endif

using namespace std;

void sec61_fixedsizearray();
void BestPractice_IO_handleCinFail();

void bestPractice_2DArrayDeclaration();
typedef vector<vector<int> > ARRAY_2D_RESIZABLE;
void helper_print2DArray1(const array<array<int, 3>, 2> &arr);
void helper_print2DArray2(const int (&arr)[2][3], int rows, int cols);
void helper_print2DArray3(const vector<vector<int> > &arr);

#endif /* LEARNCPP_6ARR_PTR_REF_H */

