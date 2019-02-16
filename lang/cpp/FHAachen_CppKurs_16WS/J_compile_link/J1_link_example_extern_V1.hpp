/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Thema external functions
 */

// prevent multiple definitions 
#if !defined(J1_FUNCTIONS)
#define J1_FUNCTIONS 1

extern int n;

inline void do_something() { int n; n=12; }

void write_something(const string& s);

class C 
{
public:
    C();
    
    int mal2(int n);
    
    static int m;
};

template <typename T>
class D
{
public:
    D();
};

#endif


