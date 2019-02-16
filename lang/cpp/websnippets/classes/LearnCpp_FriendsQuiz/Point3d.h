/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Point3d.h
 * Author: johannesw
 *
 * Created on 11. Juli 2017, 01:22
 */

#ifndef POINT3D_H
#define POINT3D_H

class Vector3d;

class Point3d {
private:
    double x, y, z;
public:
    Point3d(double x = 0.0, double y = 0.0, double z = 0.0)
    : x(x), y(y), z(z) {
    }
    void print();
    void moveByVector(Vector3d &v);
};


#endif /* POINT3D_H */

