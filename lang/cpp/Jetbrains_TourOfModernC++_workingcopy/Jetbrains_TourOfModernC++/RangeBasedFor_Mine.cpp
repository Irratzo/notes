/*
 * Self-written file for 
 * Jetbrains Tour of Modern C++
 */

#include "Headers.h"
#include "RangeBasedFor_Mine.h"

template <typename T> //already defined in header, but did only work like this
/**
 * << Overloading for cout-ing a vector. Uses std::copy and ostream_iterator.
 * Both are C++98.
 */
ostream& operator<<(ostream& out, const vector<T>& v) {
    if (!v.empty()) {
        out << '[';
        copy(v.begin(), v.end(), ostream_iterator<T>(out, ", "));
        out << "\b\b]";
    }
    return out;
}

/**
 * Showcase of usecase-dependent looping over collection, C++98 and C++11.
 * Taken from
 * http://stackoverflow.com/a/10758845
 */
void example15_forLoopCompendium_sequenceContainer() {
    //containers
    vector<char> path{'l', 'o', 'o', 'p', 'i', 'n', 'i', 's', 'f', 'u', 'n', '!', '\n'};
    typedef vector<char> Path2;
    Path2 path2{'w', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e', '!', '\n'};
    vector<int> v{1, 2, 3};

    //C++98 newbie: use a counter (better version, see below)
    for (int i = 0; i < path.size(); ++i) {
        cout << path[i];
    }

    //C++98: use an iterator
    for (vector<char>::iterator i = path.begin(); i != path.end(); ++i) {
        cout << *i; //disallow change: use const_iterator
    }

    //C++11: with auto, non-const iterator
    for (auto i = path.begin(); i != path.end(); ++i) {
        cout << *i;
    }

    //C++11: with auto, and typedef(defined): latter enables using const_iterator
    for (Path2::const_iterator i = path2.begin(); i != path2.end(); ++i) {
        cout << *i;
    }

    //C++98: improved counter version using container's member types.
    //such types must be available, e.g. via a typedef, like here.
    //The type for the vector here size_type (returned by size function)
    for (Path2::size_type i = 0; i < path2.size(); ++i) {
        cout << path[i];
    }

    //C++11: range-based for-loop, copy-by-value...
    for (int a : v) {
        a *= -1; //...is not changing v
    }
    cout << endl;

    //C++11: range-based for-loop, copy-by-reference...
    for (int& a : v) {
        a *= -1; //... enables changing v
    }
    cout << endl;

    //C++11: rbfl, copy-by-ref, const (change a disallowed)
    for (const auto& c : path) {
        cout << c; //recommended style for tasks like cout!
    }

    //C++11: rbfl: also works on in-place initializer_list
    //but (at least in Netbeans gcc) only with 'const'
    //    for (int& x: {...}){ //Netbeans error: binding 'const int' to reference of type 'int&' discards qualifiers
    for (const char& c :{'i', 'n', 'p', 'l', 'a', 'c', 'e', '\n'}) {
        cout << c;
    }

    //C++98: using std::copy and the 'iterator adaptor' ostream_iterator
    //(also works with only one ostream arg)
    //GOOD: the only one-liner, but requires specific type
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    //C++11: using C++98 std::for_each and C++11 Lambda
    //for_each is 'overkill' for cout, but good for operations, and a one-liner!
    for_each(path.begin(), path.end(), [] (const auto c) {
        cout << c;
    });

    //C++98: using generic << overloading (implementation is also C++98)
    cout << path << endl;

}

void example16_forLoop_KVContainer(){
    map<string,int> histogram {
        {"key1",98},
        {"key2",128},
        {"key3",1100010}
    };
    
    //C++11: range-based for-loop, auto, const, copy-by-ref
    for (const auto& pair: histogram){
        cout << pair.first << ',' << pair.second << endl;
    }
}