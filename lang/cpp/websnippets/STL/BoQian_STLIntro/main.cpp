/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: johannesw
 *
 * Created on 9. Juli 2017, 19:13
 * 
 * ON CMD LINE, COMPILE LIKE SO:
 * g++ -ansi -std=c++11 A01_Overview.cpp  B02_SequenceContainers.cpp main.cpp -o main.out
 * 
 */

#include "BoQuianSTLIntro.h"

/*
 * 
 */
int main(int argc, char** argv) {
    cout << "main" << endl;
    
    cout << endl << "---------01 Overview-----------------------------------------" << endl;
    boQuianSTL_01Overview();
    cout << endl;
    
    cout << endl << "---------02 Sequence Containers------------------------------" << endl;
    boQuianSTL_02SequenceContainers();


    return 0;
}

