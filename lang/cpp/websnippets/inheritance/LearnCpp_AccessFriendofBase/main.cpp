/*
 * Source: Learncpp.com 11.6a
 * Problem: Base has operator<< as Friend. Is not part of Base.
 * How to access it in Derived?
 * Solution: static_cast<Base>(derived)
 */




#include <cstdlib>
#include <iostream>

using namespace std;

class Base {
private:
    int m_value;

public:

    Base(int value)
    : m_value(value) { }

    friend std::ostream& operator<<(std::ostream &out, const Base &b) {
        out << "In Base\n";
        out << b.m_value << '\n';
        return out;
    }
};

class Derived : public Base {
public:

    Derived(int value)
    : Base(value) { }

    friend std::ostream& operator<<(std::ostream &out, const Derived &d) {
        out << "In Derived\n";
        // static_cast Derived to a Base object, so we call the right version of operator<<
        out << static_cast<Base> (d);
        return out;
    }
};

int main() {
    Derived derived(7);

    std::cout << derived;
//    std::cout << static_cast<Base>(derived);

    return 0;
}

