/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: johannesw
 *
 * Created on 7. Juli 2017, 02:48
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include "AnimalClass.h"
#include "DogClass.h"

using namespace std;

int Animal::numOfAnimals = 0;

Animal::Animal() {
    Animal::numOfAnimals++;
}

/*
 * Netbeans-Generated Parameter-Ctor
 * Behaves identically to the better known style of declaration below.
 * ---
 * Is not Cxx11-style, works in Cxx98 as well.
 */
Animal::Animal(int height, int weight, string name) :
height(height), weight(weight), name(name) {
    numOfAnimals++;
}

///*
// * My Parameter-Ctor
// * Behaves identically to the Netbeans-generated one above.
// */
//Animal::Animal(int height, int weight, string name) {
//    this->height = height;
//    this->weight = weight;
//    this->name = name;
//    numOfAnimals++;
//}

Animal::~Animal() {
    cout << "Animal " << this->name << " destroyed";
}

void Animal::toString() {
    cout << this->name << " is " << this->height << " cms tall and "
            << this->weight << " kgs in weight" << endl;
}

Dog::Dog(int height, int weight, string name, string bark) :
Animal(height, weight, name) {
    this->sound = bark;
}

void Dog::toString() {
    //using getters cause superclass vars private!
    cout << this->getName() << " is " << this->getHeight() << " cms tall and " <<
            this->getWeight() << " kgs in weight" << " and says " << this->sound << endl;
}

void banasTutorialStuff(Animal&, Animal&); //C++-Refs = "SymLinks"
void netbeansGeneratedMethodsStuff(Animal&, Dog&);

/*
 * 
 */
int main(int argc, char** argv) {

    Animal luke(210, 120, "Luke");
    Dog dog(170, 60, "spot", "woof");


    banasTutorialStuff(luke, dog);
    netbeansGeneratedMethodsStuff(luke, dog);

    return 0;
}

void banasTutorialStuff(Animal &al1, Animal &al2) {

    cout << al1.getName() << " is " << al1.getHeight() << " cms tall and "
            << al1.getWeight() << " kgs in weight" << endl;

    //    (dynamic_cast<Dog*>(al2)).getSound(); //many errors, even if al2 is ptr
    al2.getSound(); //    correct if decl as virtual
    /*
     * Note: In Java-Think, when there is no method getSound in superclass,
     * we could just try casting to Subclass Dog and call getSound on result.
     * In C++ (and generally), it makes more sense NOT to use a 
     * dynamic_cast<Dog*>(animal), because an Animal is NOT a Dog!
     * So preferred way is to declare getSound as virtual in superclass!
     * Source with more examples:
     * https://stackoverflow.com/questions/5313322/c-cast-to-derived-class
     */

    al2.toString(); //problem now: uses Animal::toString instead of Dog::toString
    //solution, virtualize toString also.
    //Now, al2 says Woof :)

    cout << "Num of Animals is " << Animal::getNumOfAnimals() << endl;
}

void nbGMS_Helper_compare(const Animal &al1, const Animal &al2){
    if (al1 > al2) {
        cout << al1.getName() << " is bigger than " << al2.getName() << endl;
    } else if (al2 > al1) {
        cout << al2.getName() << " is bigger than " << al1.getName() << endl;
    }
}

void netbeansGeneratedMethodsStuff(Animal &al1, Dog &dog) {
    nbGMS_Helper_compare(al1,dog); //notice: Dog& implicitly converted to Animal&
    //(of course, would also work on Dog, not just Dog&)
    
    Dog spark(dog); //notice: uses Animal CCtor -- no separate Dog CCtor required!
    spark.setName("spark");
    spark.toString(); //says Woof!
    nbGMS_Helper_compare(al1,spark);
    

}