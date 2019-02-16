/*
 * Self-written file for 
 * Jetbrains Tour of Modern C++
 */

#include "SmartPointers_Mine.h"

//rudimentary CCtor to verify that create_Ad. really is RBV
//Expl., see https://en.wikipedia.org/wiki/Return_value_optimization

Address::Address(const Address&) {
    cout << "Address copied!" << endl;
}

/**
 * C++98
 */
Address create_address_RBV(string postcode) {
    Address address{};
    address.postcode = postcode;
    return address;
}

/**
 * C++14
 */
unique_ptr<Address> create_address_smart(string postcode) {
    auto a = make_unique<Address>(); //make functions for smart pointers only since C++14!
    a->postcode = postcode; //init with pointer deref operator
    return a;
}

Person2_Cpp98::Person2_Cpp98() {
    Address a = Address{};
    address = &a;
}

/**
 * In the C++98 style, would init address ptr in the Ctor, delete it in the Dtor
 */
Person2_Cpp98::~Person2_Cpp98() {
    if (address) delete address; //if person dies, address dies
}

Person2_Cpp14::Person2_Cpp14() {
//        address = make_unique<Address>(); //example 19
    address = make_shared<Address>(); //example 20
}