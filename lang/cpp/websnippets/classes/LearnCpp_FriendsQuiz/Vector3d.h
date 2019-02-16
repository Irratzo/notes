/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vector3d.h
 * Author: johannesw
 *
 * Created on 11. Juli 2017, 01:23
 */

#ifndef VECTOR3D_H
#define VECTOR3D_H

#include "Point3d.h"

class Vector3d {
private:
    double x, y, z;
public:
    Vector3d(double x = 0.0, double y = 0.0, double z = 0.0)
    : x(x), y(y), z(z) {
    }
    void print();
    friend void Point3d::moveByVector(Vector3d &v);
    /*can access Vector3d's private members*/
};


#endif /* VECTOR3D_H */

