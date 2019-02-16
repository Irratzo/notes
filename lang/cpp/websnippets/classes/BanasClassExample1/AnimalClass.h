/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AnimalClass.h
 * Author: johannesw
 *
 * Created on 7. Juli 2017, 02:49
 */

#ifndef ANIMALCLASS_H
#define ANIMALCLASS_H

using namespace std;

class Animal {
private:
    int height;
    int weight;
    string name;
    static int numOfAnimals;


public:

    int getHeight() const {
        return height;
    } //getter: use const!

    int getWeight() const {
        return weight;
    }

    string getName() const {
        return name;
    }
    /*
     * Meaning of declaring a class method as foo() const: 
     * Normally, the 'this'-ptr would be of type (YourClass* const).
     * That is, a constant ptr on an object of type Yourclass.
     * Within foo() const, this is now of type (const YourClass* const).
     * That is, a constant ptr on a constant object of type Yourclass.
     * So, no members of this can be modified inside foo().
     * Generally, use this for getter methods to play safe.
     */

    Animal();
    Animal(int, int, string);
    ~Animal();

    static int getNumOfAnimals() {
        return numOfAnimals;
    } //static getter: no const!
    virtual void toString(); //no const: subclass Dog overrides; not possible together with const

    /*
     * =======The following methods are Netbeans-Generated======================
     * =========================================================================
     * Not part of Banas Tutorial
     */

    //Other Ctors (Netbeans-Generated)------------------------------------------

    /*Netbeans parametrized Ctor:*/

    /*CCtor (CopyCtor), Netbeans-Generated*/
    Animal(const Animal& other) :
    height(other.height), weight(other.weight), name(other.name) {
    }


    //Setters (Netbeans-Generated): --------------------------------------------

    void setHeight(int height) {
        this->height = height;
    }

    void setName(string name) {
        this->name = name;
    }

    void setWeight(int weight) {
        this->weight = weight;
    }

    //Operator Methods, Netbeans-Generated:

    bool operator>(const Animal& o) const {
        //        return height > o.getHeight(); //correct!
        //        return height > o.height; //correct!
        //        return height > o->height; //ERROR: o of non-ptr-type "const Animal"!!!
        //        return height > o->getHeight(); //ERROR: o of non-ptr-type "const Animal"!!!

        return (height > o.height) && (weight && o.weight);
    }

    bool operator<(const Animal& right) const {
        return right > * this; // Reuse greater than operator
    }

    //Needed since rewrite of main() to call methods with handing down 
    //instantiated Animals by References:
    //virtual method in superclas 

    virtual void getSound() const {
        cout << "Grrrr..!" << endl;
    }





};



#endif /*ANIMALCLASS_H*/

