/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: johannesw
 *
 * Created on 13. Juli 2017, 10:46
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "LinkedListETHZ.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    LinkedListETHZ<double> sili;
    sili+=.5; //overloaded +=
    sili+=.12;
    
    
    
//    sili = sili + .6; //operator+ buggy at the moment, TODO
    cout << "list numOfValues: " << sili.getLength() << endl;
    cout << "list sumOfValues: " << sili.getSumOfValues() << endl;

    return 0;
}

