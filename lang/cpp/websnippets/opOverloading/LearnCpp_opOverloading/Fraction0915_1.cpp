/*
 * Example for:
 * - overloading << operator for IO Stream
 * - overloading assignment operator for shallowCopy (ok cause no 
 * dynMem members)
 */

#include "Fraction0915_1.h"

/* A better implementation of operator=*/
Fraction& Fraction::operator=(const Fraction &fraction) {
    // self-assignment guard
    if (this == &fraction)
        return *this;

    // do the copy 
    //(copy by assignment = shallow-copy; 
    // okay cause no dynMem members)
    num = fraction.num;
    denom = fraction.denom;

    // return the existing object so we can chain this operator
    return *this;
}
