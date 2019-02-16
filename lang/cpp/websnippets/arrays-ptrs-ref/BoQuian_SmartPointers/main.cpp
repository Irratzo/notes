/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: johannesw
 *
 * Created on 14. Juli 2017, 01:23
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <memory> //smartPtrs

using namespace std;

class Dog{
protected:
    string name;
    public:
        Dog(string name) : name{name} { cout << "A new Dawg has risen, he's " << name << endl;}
        Dog(){ cout << "A new Nameless Dog, probably a wolf" << endl;}
        ~Dog(){ cout << "Dog " << name << " HAS BEEN DESTROYED (by argument)!" << endl;}
        virtual void bark(){ cout << "Woof, said " << name << endl;}
};

class Hound : public Dog{
public: Hound(string name) : Dog(name){}
void bark(){ cout << "I'm a Hound, no matter what you point at me!, said " << name << endl;}
};

void oldWay_dontCallThis(){ //dont do this anymore
    Dog *p = new Dog("TheGood");
    //...
//    delete p; //OH NO!
    //...
    p->bark(); //danglingPtr undefined behaviour
} //memory leak if not deleted

void newWay_callThis_Uhoh(){
//    shared_ptr<Dog> p(new Dog("TheBad"));
    shared_ptr<Dog> p = make_shared<Dog>("The Ugly"); //yes! //p.use_count()=1
    {
        shared_ptr<Dog> p2 = make_shared<Dog>("Pepe"); //que? //count=2
        p2->bark();
    }//count=1
}//count=0

void rawPtrsShouldNotBeUsedAgain(){
    Dog *d = new Dog();
    shared_ptr<Dog> p(d); //count=1
    shared_ptr<Dog> p2(d); //count=1! if one goes out of scope, the other is dangling!
    /*assign obj to smartPtr AS SOON AS IT IS CREATED!*/
}

void commonPointerOperationsWithSmartPtrs(){
    shared_ptr<Hound> p = make_shared<Hound>("Zuzu");
    p->bark(); //arrow!
    (*p).bark(); //dereference!
    //SPECIAL castFcts for SmartPtrs!
    shared_ptr<Dog> p2 = static_pointer_cast<Dog>(p);
    shared_ptr<Dog> p3 = dynamic_pointer_cast<Dog>(p);
//    shared_ptr<Dog> p4 = const_pointer_cast<Dog>(p); //error!
    p2->bark(); //still a Hound deep inside
    p3->bark(); //still a Hound deep inside
}

void whenSmartPtrsGoOutOfScope(){
    shared_ptr<Dog> p1 = make_shared<Dog>("The Ugly");
    shared_ptr<Dog> p2 = make_shared<Dog>("Rantanplan");
    shared_ptr<Dog> p3 = p2;
    p1 = p2; //The Ugly is DESTROYED!
    p2 = nullptr; //Responsibility moved to p3
    p3.reset(); //Rantanplan is DESTROYED!
}

void usingACustomDeleterOnAnArrayOfDogs(){
    /*in such a case the default deleter wont do. We create one with Lambda.*/
//    shared_ptr<Dog> p3(new Dog[3]); //ptr just points to the first dog
    /*Deleting the ptr would just delete the first dog, memleak for dog2, dog3*/
    
    //custom deleter:
    shared_ptr<Dog> p4(new Dog[3], [](Dog *p){delete[] p;});
    
}
/*
 * 
 */
int main(int argc, char** argv) {
    
//    oldWay_dontCallThis();
    newWay_callThis_Uhoh();
    cout << endl;
//    rawPtrsShouldNotBeUsedAgain();
    commonPointerOperationsWithSmartPtrs();
    cout << endl;
    whenSmartPtrsGoOutOfScope();
    cout << endl;
    usingACustomDeleterOnAnArrayOfDogs();

    return 0;
}

