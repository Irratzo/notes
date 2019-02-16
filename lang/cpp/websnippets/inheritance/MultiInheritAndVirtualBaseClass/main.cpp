/*
 * Example for Conflicting multiple inheritance over three levels: 
 * (A, B:A, C:A, D:B,C). C inherits twice from A.
 * Solution to prevent duplication of C members in A: make A a virtualBaseClass:
 * (A, B: virtual A, C: virtual B, D: B,C).
 * Additionally, in D Ctor:
 * - D Ctor now has to invoke A Ctor instead of B and C Ctors, so:
 *   D(D args) : A(A args), B(B args), C(C args)
 * - all D Ctor previouly captured by B,C Ctors but now captured by A Ctor, set to 0:
 *   D(D args) : A(A args), B(B args, A args = 0), C(C args, A args = 0)
 *
 * ===========================================================================
 * 
 * Also showcases how to adapt an enum for cout via overloading operator<< with
 * a map<MyEnum,string>. 
 *
 */

/* 
 * File:   main.cpp
 * Author: johannesw
 *
 * Created on 12. Juli 2017, 14:40
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <map>

using namespace std;

enum SEX {
    FEMALE,
    MALE,
    UNSPECIFIED
};



enum class LANGUAGE {
    CPP,
    JAVA,
    UNSPECIFIED
};

std::ostream& operator<<(std::ostream& out, const SEX value) {
    static std::map<SEX, std::string> strings;
    if (strings.size() == 0) {
#define INSERT_ELEMENT(p) strings[p] = #p
        INSERT_ELEMENT(FEMALE);
        INSERT_ELEMENT(MALE);
        INSERT_ELEMENT(SEX::UNSPECIFIED);
#undef INSERT_ELEMENT
    }

    return out << strings[value];
}

std::ostream& operator<<(std::ostream& out, const LANGUAGE value) {
    static std::map<LANGUAGE, std::string> strings;
    if (strings.size() == 0) {
#define INSERT_ELEMENT(p) strings[p] = #p
        INSERT_ELEMENT(LANGUAGE::CPP);
        INSERT_ELEMENT(LANGUAGE::JAVA);
        INSERT_ELEMENT(LANGUAGE::UNSPECIFIED);
#undef INSERT_ELEMENT
    }

    return out << strings[value];
}

//map<SEX, string> mapSEX{
//    {FEMALE, "FEMALE"},
//    {MALE, "MALE"},
//    {UNSPECIFIED, "UNSPECIFIED"}};
////map<LANGUAGE, string> mapLANG{{JAVA,"CPP"},{JAVA,"JAVA"},{UNSPECIFIED,"UNSPECIFIED"}};

class Human {
    string name;
    SEX sex;
public:

    Human(string name, SEX sex = SEX::UNSPECIFIED) : name(name), sex(sex) { }

    string GetName() const {
        return name;
    }

    SEX GetSex() const {
        return sex;
    }
};

class Coder : public virtual Human { //<- virtual, also in Woman: avoids CoderGirl getting 2 Humans
    LANGUAGE lang;
public:

    Coder(string name, LANGUAGE lang = LANGUAGE::UNSPECIFIED) : Human(name), lang(lang) { }

    LANGUAGE GetLang() const {
        return lang;
    }
};

class Woman : public virtual Human { //<- virtual, also in Coder: avoids CoderGirl getting 2 Humans
public:

    Woman(string name) : Human(name, FEMALE) { }
};

class CoderGirl : public Coder, public Woman {
public:

    CoderGirl(string name, LANGUAGE lang) : Human(name, FEMALE), Coder(0, lang), Woman(0) { }
    /*
     * Adaptation to Human being virtualBaseClass: lowest derived class, CoderGirl, now has to call 
     * Human Ctor first, instead of just Coer and Woman. All Human Ctor args in the latter two
     * can now be set to 0, since they don't get used anyway.
     */
};

/*
 * 
 */
int main(int argc, char** argv) {

    Coder c{"Hannah", LANGUAGE::CPP};
    cout << "CoderGirl: " << c.GetName() << ", " << c.GetSex() << ", " << c.GetLang() << endl;

    return 0;
}

