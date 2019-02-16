/*
 * Example showcasing Class Relationship aggregation (-> Address.h)
 */

/* 
 * File:   Person.h
 * Author: johannesw
 *
 * Created on 11. Juli 2017, 18:16
 */

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iomanip>

class Person {
private:
    std::string name;
    int age;

public:

    Person() {
    }

    Person(std::string name, int age) :
    name(name), age(age) {
    }

    friend std::ostream& operator<<(std::ostream& out, const Person &p);

    std::string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

};

/* Note: external function, no Person:: scope*/
std::ostream& operator<<(std::ostream& out, const Person &p) {
    out << std::setw(23) << std::left << p.name
            << std::setw(12) << std::right << ", aged " << p.age << std::endl;
    return out;
}



#endif /* PERSON_H */

