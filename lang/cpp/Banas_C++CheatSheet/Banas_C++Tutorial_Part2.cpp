//source: http://www.newthinktank.com/2014/11/c-programming-tutorial/
//#include <iostream>

#if defined(_WIN32) || (defined(__APPLE__) && defined(__MACH__))
#include <cstdio>
#include <iostream> //for cout
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional> //for Lambdas
#include <memory>
#include <type_traits>
#include <initializer_list> //for decltype
#else
#include <bits/stdc++.h> //import all you need (possible with e.g. gcc)
#endif

using namespace std;

// Virtual Methods and Polymorphism
// Polymorpism allows you to treat subclasses as their superclass and yet
// call the correct overwritten methods in the subclass automatically

class Aanimal {
public:
    
    Aanimal(){}

    explicit Aanimal(int legs) : legs(legs) {
        //used for resetting default value in derived class Ctors
    }

    void getFamily() {
        cout << "We are Animals" << endl;
    }

    // When we define a method as virtual we know that Animal
    // will be a base class that may have this method overwritten

    virtual void getClass() {
        cout << "I'm an Animal" << endl;
    }
    
    void getLegs(){
        printf("I have %d legs\n",legs);
    }
protected:
    int legs = 4; //C++11: default values possible
};

class Dog : public Aanimal {
public:

    void getClass() {
        cout << "I'm a Dog" << endl;
    }

};

class GermanShepard : public Dog {
public:

    void getClass() {
        cout << "I'm a German Shepard" << endl;
    }

    void getDerived() {
        cout << "I'm an Animal and Dog" << endl;
    }

};

class Spider : public Aanimal {
public:

    Spider() : Aanimal(8) {
    }

    void getClass() {
        cout << "I'm a spider" << endl;
    }
};

void whatClassAreYou(Aanimal *animal) {
    animal -> getClass();
}

/**
 * Comment out other main.
 */
int main() {

    Aanimal *animal = new Aanimal;
    Dog *dog = new Dog;

    // If a method is marked virtual or not doesn't matter if we call the method
    // directly from the object
    animal->getClass(); //animal
    dog->getClass(); //dog

    // If getClass is not marked as virtual outside functions won't look for 
    // overwritten methods in subclasses however (banas)
    whatClassAreYou(animal); //animal
    whatClassAreYou(dog); //dog, so no problem after all (jw)???

    Dog spot;
    GermanShepard max;

    // A base class can call derived class methods as long as they exist 
    // in the base class
    Aanimal* ptrDog = &spot;
    Aanimal* ptrGShepard = &max;

    // Call the method not overwritten in the super class Animal
    ptrDog -> getFamily(); //animals

    // Since getClass was overwritten in Dog call the Dog version
    ptrDog -> getClass();

    // Call to the super class
    ptrGShepard -> getFamily();

    // Call to the overwritten GermanShepard version
    ptrGShepard -> getClass();
    
    Spider spider;
    spider.getLegs();

    return 0;
}
