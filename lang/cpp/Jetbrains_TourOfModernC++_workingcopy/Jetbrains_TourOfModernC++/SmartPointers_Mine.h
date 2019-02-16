/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SmartPointers_Mine.h
 * Author: johannesw
 *
 * Created on 5. Januar 2017, 15:57
 */

#ifndef SMARTPOINTERS_MINE_H
#define SMARTPOINTERS_MINE_H

#include "Headers.h"

class Address {
public:
    Address() {}
    Address(const Address&); //rudimentary CCtor to verify that create_address really is RBV
    int housenumber;
    string city;
    string postcode;
};

/**
 * C++98: One way of providing a global Address instancer: return-by-value (RBV).
 */
Address create_address_RBV(string postcode);

unique_ptr<Address> create_address_smart(string postcode);

/**
 * The old way of mem-managing the Person's Address pointer member (dynamic)
 */
class Person2_Cpp98 {
public:
    Address* address; //store Address as a pointer
    Person2_Cpp98();
    ~Person2_Cpp98();
};

class Person2_Cpp14 {
public:
//    unique_ptr<Address> address; //example 19
    shared_ptr<Address> address; //example 20
    Person2_Cpp14();
    //no Dtor needed :)
};




#endif /* SMARTPOINTERS_MINE_H */

