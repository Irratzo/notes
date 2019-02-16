/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: johannesw
 *
 * Created on 7. Juli 2017, 04:09
 */

#include <cstdlib>
#include <iostream>

using namespace std;

class Animal{
public:
    virtual void makeSound() const { cout << "The Animal says grr" << endl;}
};

class Dog : public Animal{
public:
     void makeSound() const { cout << "The Dog says woof" << endl;}

};

class Cat : public Animal{
    public:
    void makeSound() const { cout << "The Cat says meow" << endl;}
};

/*
 * Example of abstract class
 */
class Car{
public:
    virtual int getNumWheels() const = 0; //extract method syntax
    virtual int getNumDoors() const = 0;
};

class StationWagon : public Car{
public:
    int getNumWheels() const { cout << "Station Wagon has 4 wheels" << endl;}
    int getNumDoors() const { cout << "Station Wagon has 4 doors" << endl;}
    StationWagon(){}
    ~StationWagon();
};
/*
 * 
 */
int main(int argc, char** argv) {
    
    Animal *pCat = new Cat;
    Animal *pDog = new Dog;
    pCat ->makeSound();
    pDog ->makeSound();
    
    Car* stationWagon = new StationWagon();
    stationWagon->getNumDoors();
    stationWagon->getNumWheels();

    return 0;
}

