/*
 * Example for:
 * - overloading << operator for IO Stream
 * - overloading assignment operator for shallowCopy (ok cause no 
 * dynMem members)
 */

/* 
 * File:   Fraction0915_1.h
 * Author: johannesw
 *
 * Created on 11. Juli 2017, 16:51
 */

#ifndef FRACTION0915_1_H
#define FRACTION0915_1_H

#include <cassert>
#include <iostream>

class Fraction {
private:
    int num; //numerator
    int denom; //denominator

public:
    // Default constructor

    Fraction(int numerator = 0, int denominator = 1) :
    num(numerator), denom(denominator) {
        assert(denominator != 0);
    }

    // Copy constructor

    Fraction(const Fraction &f) :
    num(f.num), denom(f.denom) {
    }

    Fraction& operator=(const Fraction &fraction);

    friend std::ostream& operator<<(std::ostream& out, const Fraction &f1);
};

std::ostream& operator<<(std::ostream& out, const Fraction &f1) {
    out << f1.num << "/" << f1.denom;
    return out;
}





#endif /* FRACTION0915_1_H */

