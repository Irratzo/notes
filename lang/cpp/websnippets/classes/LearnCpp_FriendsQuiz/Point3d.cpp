/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "Point3d.h"
#include "Vector3d.h"

void Point3d::print() {
    std::cout << "Vector(" << x << ", " << y << ", " << z << ")\n";
}

/**
 * Since declared as friend to Vector3d, can access Vector3d's private members
 * @param v
 */
void Point3d::moveByVector(Vector3d &v) {
    x += v.x;
    y += v.y;
    z += v.z;
}