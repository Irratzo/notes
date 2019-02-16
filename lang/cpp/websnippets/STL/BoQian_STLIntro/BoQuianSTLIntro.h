/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   boQuian.h
 * Author: johannesw
 *
 * Created on 9. Juli 2017, 19:20
 */

#ifndef BOQUIAN_H
#define BOQUIAN_H

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
#else
#include <bits/stdc++.h>
#endif

using namespace std;

void boQuianSTL_01Overview();
void boQuianSTL_02SequenceContainers();
template <class T>
void b02_printLists(list<T> li1, list<T> li2);





#endif /* BOQUIAN_H */

