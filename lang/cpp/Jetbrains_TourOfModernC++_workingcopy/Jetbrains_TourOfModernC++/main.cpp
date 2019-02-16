/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: johannesw
 *
 * Created on 2. Januar 2017, 18:10
 */

#include <cstdlib>
#include <iostream>
#include "Headers.h"
#include "AutoDeclType_Mine.h" //example 02 to example 05
#include "InitAndCtorInheritance_Mine.h" //example 06 to example 09
#include "Lambdas_Mine.h" //example 10 to example 12
#include "StronglyTypedEnum_Mine.h" //example 13 to example example 14
#include "RangeBasedFor_Mine.h" //example 15, example 16
#include "StaticAssertTraits_Mine.h" //example 17, example 18
#include "SmartPointers_Mine.h" //example 19,
using namespace std;

struct Person {
    string name;
    int age;
    string children[2];

    Person(string name, int age) :
    name(name), age(age) {
    }

    Person(const Person& other) :
    name(other.name), age(other.age) {
    }

    Person(initializer_list<string> kids) {
        if (kids.size() < 2) return;

        auto c = kids.begin();
        children[0] = *c;
        c++;
        children[1] = *c;
    }


};

/**
 * Jetbrains Tour of Modern C++ - Example 01
 * Uniform initilization ({} initialization)
 */
void uniform_initialization_example() {
    int n{42};
    Person p{"Alf", n};
    cout << "Hi, " << p.name << "! Wow, you're " << p.age << " years old!\n";

    Person p2{"maggie", "ronald"};
    cout << "This person has two kids: " << p2.children[0] << " and " << p2.children[1] << ".\n";



}

/**
 * Jetbrains Tour of Modern C++ - Example 03
 * auto-return function not included via header elsewhere:
 * Can use C++14-style *without* trailing lambda specifying return type (C++11-style)
 * @return 
 */
auto meaning_of_life_C14() {
    return 9 * 6;
}

template<typename T, typename U>
/**
 * Jetbrains Tour of Modern C++ - Example 04
 * Decltype for simpler template generation.
 * Actually, belongs into AutoDeclType_Mine.cpp, but linking via header
 * didn't work here.
 */
auto add_generic(T t, U u) { //C++11-style: add "-> decltype(t+u) {...}"
    return t + u;
}

/*
 * 
 */
int main(int argc, char** argv) {

    //example 01:
    //uniform_initialization_example();

    //example 02:
    autoDeclType_example();

    //example 03:
    cout << meaning_of_life_C11() << endl;
    cout << meaning_of_life_C14() << endl;

    //example 04:
    cout << add_generic(3, 4.5) << endl;
    cout << add_generic(string("hello"), string(" world\n"));

    //example 05: declaring and extracting types with decltype
    vector<double> values;
    typedef decltype(values.begin()) doublevalueiterator;
    typedef decltype(42) myveryowninttype;
    typedef decltype(add_generic(3, 4.5)) someothertype;
    typedef decltype(42, 'z') averysillychartype; //only evaluates 'z'

    //examples 06 to 08: see InitAndCtorInheritance_Mine
    //example 09: deleted copy-ctor:
    Human h;
    //    Human h2{h};//would throw error: use of deleted function 'Human::Human(const Human&)'

    example11_lambda2();
    example12_lambda3_fibonacci();

    //example 13, 14 (enum classes) see StronglyTypedEnum_Mine

    example15_forLoopCompendium_sequenceContainer();
    example16_forLoop_KVContainer();

    //example 17, 18: see StaticAssertTraits_Mine. TODO: header file

    //example 19: check if create_address really does RBV, i.e. no copying
    //if no "Address copied!" output appears, both copies were eliminated by
    //the compiler.
    //Expl. see https://en.wikipedia.org/wiki/Return_value_optimization
    auto my_address = create_address_RBV("D-79733");
    auto my_smart_address = create_address_smart("D-79733");

    //example 20: shared_ptr
    //this does not work with a unique_ptr. (Person::adddress also has to be shared_ptr!)
    //    unique_ptr<Address> a; //error
    shared_ptr<Address> a; //works
    { //separate scope
        Person2_Cpp14 p;
        p.address->city = "Zurich";
        a = p.address; //error if unique_ptr, OK if shared_ptr
    }

    return 0;
}

