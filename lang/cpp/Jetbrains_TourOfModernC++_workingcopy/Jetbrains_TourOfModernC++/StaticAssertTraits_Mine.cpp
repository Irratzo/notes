/*
 * Self-written file for 
 * Jetbrains Tour of Modern C++
 */

#include "Headers.h"
#include "StaticAssertTraits_Mine.h"

/*
 * Suppose that I'm making some type which accesses an array. So I have a
   template with the type generic type ~T~ of the element that we are storing,
   plus the size of the parameter ~size_t~. *Reminder*: ~size_t~ is a datatype
   (~typedef~) representing the /size of an object/. Library functions that take
   sizes /expect them to be of type/ ~size_t~, and the ~sizeof~ operator
   evaluates to ~size_t~; a common mistake is to assume ~size_t~ is the same as
   ~unsigned int~ - it is not!
 * Now suppose, I only want this class to be used if the ~Size~ is greater than
   one, otherwise I want people to use a /scalar/ (type) instead.
   ~static_assert~ allows to check this /at compile-time/:
 */


template <typename T, size_t Size>
class Values {
    static_assert(Size > 1, "Use a scalar"); //2nd arg: else
    T values[Size];
};

/**
 * TODO: Before usage, separate Values definition into header and cpp file!
 */
void example17_staticAssert() {
    Values<int, 3> stuff; //OK!
//    Values<int, 1> trash; //error: Use a scalar
};

