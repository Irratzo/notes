/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DogClass.h
 * Author: johannesw
 *
 * Created on 7. Juli 2017, 03:22
 */

#ifndef DOGCLASS_H
#define DOGCLASS_H

#include "AnimalClass.h"

class Dog : public Animal {
private:
    string sound;
public:
    void getSound() const {cout << sound << endl;}
    
    Dog(int, int, string, string); //new Ctor
    Dog() : Animal(){}; //inheriting superclass Ctor
    
    void toString(); //overriding superclass method

};

#endif /* DOGCLASS_H */

