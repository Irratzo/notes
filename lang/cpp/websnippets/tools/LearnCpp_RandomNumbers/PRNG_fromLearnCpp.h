/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PRNG_fromLearnCpp.h
 * Author: johannesw
 *
 * Created on 13. Juli 2017, 13:45
 */

#ifndef PRNG_FROMLEARNCPP_H
#define PRNG_FROMLEARNCPP_H

#include <cstdlib> // for rand() and srand()
#include <ctime> // for time() 
int randTime()
{
    srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
    return rand();
}

// Generate a random number between min and max (inclusive)
// Assumes srand() has already been called
int randRange(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
    // evenly distribute the random number across our range
    return static_cast<int>(randTime() * fraction * (max - min + 1) + min);
}

#endif /* PRNG_FROMLEARNCPP_H */

