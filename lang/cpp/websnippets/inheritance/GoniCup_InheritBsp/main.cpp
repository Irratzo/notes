/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: johannesw
 *
 * Created on 12. Juli 2017, 11:36
 */

#include <cstdlib>
#include <iostream>
#include <iomanip> //if used
#include "../../tools/tools.h"

using namespace std;

class A {
private:

    printA(string method) {
        cout << "Called A::" << method << endl;
    }
protected:
    int n;
public:

    A() {
        printA("DefCtor");
    }

    A(int N) : n(N) {
        printA("ParamCtor");
    }

    void f() {
        printA("f");
    } //nimm immer die methode des dynamischen Types

    virtual void g() {
        printA("g");
    } //nimm immer die methode des statischen Types

    virtual void h() {
        printA("h");
    } //nimm immer die methode des statischen Types

    virtual void i() final {
        printA("i");
    } //final methode kann nicht überschieben werden
};

class B : public A { //B erbt von A
private:
    int m;

    printB(string method) {
        if (method.find("Ctor") != std::string::npos) {
            /*called implicitly after A-Ctor, needs additional tools line*/
            tools_log(); cout << "Called B::" << method << endl;
        } else {
        cout << "Called B::" << method << endl;
        }
    }
public:

    B() {
        printB("DefCtorB");
    }

    B(int N) : A(N) {
        printB("ParamCtor");
    }

    void f() {
        printB("f");
    } //verdeckt die methode
    //virtual void f(){}			//für alle kinder ist es virtual, aber nicht wenn man als dynamischen Type A hat

    virtual void g() {
        printB("g");
    } //überschreibt die methode

    void h() {
        printB("h");
    } //überschreibt die methode und ist immernoch virtual
    //virtual void i() final {}		//geht nicht, da es final ist
};

/*
 * 
 */
int main(int argc, char** argv) {
    
    tools_log(); cout << "===============Section 1: static alloc===============" << endl;
    tools_log(); A a; //called A::DefCtor
    tools_log(); B b; //called A::DefCtor, B::DefCtor
    tools_log(); A b2;
    //normal
    tools_log(); a.f(); //gibt A::f() aus
    tools_log(); a.g(); //gibt A::g() aus
    tools_log(); a.h();
    tools_log(); b.f(); //gibt B::f() aus
    tools_log(); b.g(); //gibt B::g() aus
    tools_log(); b.h();
    tools_log(); cout << "===============Section 2: dynMem alloc===============" << endl;
    //Dynamischer Type ist A
    tools_log(); A* ap = new A(); //called A::DefCtor
    tools_log(); A* bp = new B(); //called A::DefCtor, B::DefCtor
    tools_log(); ap->f(); //gibt A::f() aus
    tools_log(); ap->g(); //gibt A::g() aus
    tools_log(); ap->h(); //gibt A::h() aus
    tools_log(); bp->f(); //gibt A::f() aus, weil es in A nicht virtual ist
    tools_log(); bp->g(); //gibt B::g() aus
    tools_log(); bp->h(); //gibt B::h() aus, obwohl in B nicht virtual steht

    tools_log(); cout << "=====Section 3: Refs to staticMem objs from Sect1====" << endl;
    //Als Referenz verhält es sich genauso wie als pointer
    A& ar = a;
    A& br = b;
    tools_log(); ar.f(); //gibt A::f() aus
    tools_log(); ar.g(); //gibt A::g() aus
    tools_log(); ar.h();
    tools_log(); br.f(); //gibt A::f() aus, weil es in A nicht virtual ist
    tools_log(); br.g(); //gibt B::g() aus
    tools_log(); br.h();

    return 0;
}

