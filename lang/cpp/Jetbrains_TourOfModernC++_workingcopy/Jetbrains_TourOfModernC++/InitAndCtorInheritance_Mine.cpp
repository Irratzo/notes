/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "InitAndCtorInheritance_Mine.h"

/**
 * Jetbrains Tour of Modern C++ - Example 06
 * Default value initialization
 */
//Ctor
Animal::Animal(int legs) :
legs(legs) {
}

int Animal::walk(int steps) {
    return steps * 20; //20 = gait size or sth.
}

int Human::walk(int steps) { //obligatory override else vtable compiler error!
    return steps * 5;
}
