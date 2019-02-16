/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: johannesw
 *
 * Created on 11. Juli 2017, 00:58
 * 
 * Quiz question from: http://www.learncpp.com/cpp-tutorial/813-friend-functions-and-classes/
 * Task: implement function to translate point along vector using friend 
 * member function, function: Point3d::moveByVector(Vector3d &v)
 * 
 * COMPILE LIKE (without Netbeans):
 * g++ -ansi -std=c++11 Vector3d.cpp Point3d.cpp main.cpp -o main.out
 * 
 * Solution Notes:
 * - separated into header and cpp files for each class
 * - resolving dependencies: 
 *   - there is no problem with cyclic dependencies
 *   - each file only has to know the minimum necessity of the other class:
 *     - if file needs only to know other class, use forward declaration:
 *       class Other;
 *     - if file needs to know class other class member, include header:
 *       #include "Other.h"
 * 
 */

#include <cstdlib>
#include "Vector3d.h"
#include "Point3d.h"


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Point3d p(1.0, 2.0, 3.0);
    Vector3d v(2.0, 2.0, -3.0);

    p.print();
    p.moveByVector(v);
    p.print();

    return 0;
}

