/*
 * Example showcasing Class Relationship aggregation
 * using Person vector instead of dynamic array
 */


/* 
 * File:   AddressWithVector.h
 * Author: johannesw
 *
 * Created on 12. Juli 2017, 08:41
 */

#ifndef ADDRESSWITHVECTOR_H
#define ADDRESSWITHVECTOR_H

#include <array>
#include <vector>
#include <string>
#include <iomanip>
#include "Person.h"


class AddressUsingVector {
private:
    std::string street;
    uint16_t no; //to 2^16
    uint32_t zipcode; //to 2^32
    std::string city;


    //    std::vector<Person> ps;
    std::array<std::string, 4> loc; //location
    int residentCount;
//    std::array<Person, residentCount> resident; //does not work: count not known!
    std::vector<Person> resident;
public:

    enum AddressFields {
        STREET,
        NO,
        ZIPCODE,
        CITY
    };

    AddressUsingVector(std::string street, uint16_t no, uint32_t zipcode,
            std::string city, std::vector<Person> persons) :
    street{street}, no{no}, zipcode{zipcode}, city{city}, resident{persons} {
        /*difference to using dynArray: can just simply copy vector!*/
    }


    friend std::ostream& operator<<(std::ostream& out, const AddressUsingVector &a);
};

std::ostream& operator<<(std::ostream& out, const AddressUsingVector &a) {
    out << std::setw(10) << std::left << "Street:"
            << std::setw(25) << std::right << a.street << std::endl
            << std::setw(10) << std::left << "No.:"
            << std::setw(25) << std::right << a.no << std::endl
            << std::setw(10) << std::left << "Zipcode:"
            << std::setw(25) << std::right << a.zipcode << std::endl
            << std::setw(10) << std::left << "City:"
            << std::setw(25) << std::right << a.city << std::endl;

    out << "People living here:" << std::endl;
    for (auto p : a.resident){
        std::cout << p;
    }
    
    return out;
}

#endif /* ADDRESSWITHVECTOR_H */

