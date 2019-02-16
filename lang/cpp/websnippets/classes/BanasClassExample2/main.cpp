/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * 
 * Just shows off simple polymorphism using a virtual method.
 * 
 * File:   main.cpp
 * Author: johannesw
 *
 * Created on 7. Juli 2017, 03:53
 */

#include <cstdlib>
#include <iostream>

using namespace std;

class Animal {
public:
        void getFamily() const {
        cout << "We are Animals" << endl;
    }
    //    void getClass(){ cout << "I'm an animal" << endl;}

    virtual void getClass() const {
        cout << "I'm an animal" << endl;
    }
};

class Dog : public Animal {
public:

    void getClass() const {
        cout << "I'm a Dog" << endl;
    }
};

class GermanShepard : public Dog {
public:

    void getClass() const {
        cout << "I'm a German Shepard" << endl;
    }

    void getDerived() const {
        cout << "I'm an Animal and Dog" << endl;
    }
};

void whatClassAreYou(Animal *animal) {
    animal->getClass();
    //polymorphism: find the right method to call
}

int main(int argc, char** argv) {

    Animal *animal = new Animal;
    Dog *dog = new Dog;

    animal->getClass(); //"Animal"
    dog->getClass(); //with and without virutal: "Dog"

    whatClassAreYou(animal); //"Animal"
    whatClassAreYou(dog); //without virtual: "Animal" !!!!!!!!!!!!!
    //with virtual: "Dog" --> polymorphism!


    Dog spot;
    Animal* ptrAnimal1 = &spot;
    ptrAnimal1->getFamily(); //polymorphism: call superclass
    ptrAnimal1->getClass(); //w virtual: "Dog". polymorphism again.

    GermanShepard max;
    Animal* ptrAnimal2 = &max;
    ptrAnimal2->getFamily(); //same as above. getDerived() not available of course
    
//    GermanShepard* ptrGShepard = &spot; //runtime ERROR: invalid conversion Dog* -> GShepard*


    return 0;
}

