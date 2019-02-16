/*
 * Example showcasing Class Relationship aggregation 
 * using Person dynamic array
 */

/* 
 * File:   Address.h
 * Author: johannesw
 *
 * Created on 11. Juli 2017, 18:17
 */

#ifndef ADDRESS_H
#define ADDRESS_H

#include <array>
#include <vector>
#include <string>
#include <iomanip>
#include "Person.h"

//template <class RET>
class Address {
private:
    std::string street;
    uint16_t no; //to 2^16
    uint32_t zipcode; //to 2^32
    std::string city;


    //    std::vector<Person> ps;
    std::array<std::string, 4> loc; //location
    Person* resident;
    int residentCount;
public:

    enum AddressFields {
        STREET,
        NO,
        ZIPCODE,
        CITY
    };

    Address(std::string street, uint16_t no, uint32_t zipcode,
            std::string city, Person *persons, int noPersons) :
    street{street}, no{no}, zipcode{zipcode}, city{city}
, residentCount(noPersons) {
        resident = new Person[noPersons];
        for (int i = 0; i < noPersons; i++) {
            std::string name = persons[i].getName();
            int age = persons[i].getAge();
            resident[i] = Person(name, age);
        }
    }

    ~Address() {
        delete[] resident;
    }

//    RET get(AddressFields field) {
//        switch (field) {
//            case STREET:
//                return street;
//            case NO:
//                return no;
//            case ZIPCODE:
//                return zipcode;
//            case CITY:
//                return city;
//            default:
//                return "";
//        }
//    }

    friend std::ostream& operator<<(std::ostream& out, const Address &a);
};

std::ostream& operator<<(std::ostream& out, const Address &a) {
    out << std::setw(10) << std::left << "Street:"
            << std::setw(25) << std::right << a.street << std::endl
            << std::setw(10) << std::left << "No.:"
            << std::setw(25) << std::right << a.no << std::endl
            << std::setw(10) << std::left << "Zipcode:"
            << std::setw(25) << std::right << a.zipcode << std::endl
            << std::setw(10) << std::left << "City:"
            << std::setw(25) << std::right << a.city << std::endl;

    out << "People living here:" << std::endl;
    Person *p = a.resident;
    for (int i = 0; i < a.residentCount; i++) {
        out << *p;
        p++;
    }

    return out;
}

#endif /* ADDRESS_H */

