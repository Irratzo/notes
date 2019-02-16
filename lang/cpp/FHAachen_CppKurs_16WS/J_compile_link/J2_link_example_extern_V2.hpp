/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Thema external functions
 */

// prevent multiple definitions 
#if !defined(J2_FUNCTIONS)
#define J2_FUNCTIONS 1

template <typename T>
class D
{
public:
    D();
};

template <typename T>
D<T>::D() { tools_log(); cout << "ctor" << endl; }

#endif


