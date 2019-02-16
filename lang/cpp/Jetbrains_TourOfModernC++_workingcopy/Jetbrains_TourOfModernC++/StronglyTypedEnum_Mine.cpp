/*
 * Self-written file for 
 * Jetbrains Tour of Modern C++
 */


#include "StronglyTypedEnum_Mine.h"

/**
 * Shows off problems with C++98 enums.
 */
void example13_oldEnums() {

    OldColor oc = Green; //Enum-vals 'bleed' into this scope, 'Green' is all over the place
    int g = oc; //automatic int-casting compiles, but often undesired behavior

}

void example14_newEnums1() {

    NewColor nc = NewColor::Magenta;
    //    int n = nc; //does not work anymore

}