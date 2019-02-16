/*
 * Self-written file for 
 * Jetbrains Tour of Modern C++
 */
#include "Headers.h"
#include "Lambdas_Mine.h"

void example10_lambda1() {
    vector<int> scores{8, 2, 4, 1};

    for_each(begin(scores), end(scores), [](int n) -> float {
        cout << n << endl;
        return n; //optional
    });

}

/**
 * Accessing external variables
 */
void example11_lambda2() {
    vector<int> scores{8, 2, 4, 1};

    auto zero = 0;
    //    auto is_positive = [](int n){return n > zero;}; //error: zero not captured
    //    auto is_positive = [zero](int n){return n > zero;}; //zero capt.ed-by-value
    auto is_positive = [ = ](int n){return n > zero;}; //all capt.ed vars capt.ed-by-value
    //    auto is_positive = [ &zero ](int n){return n > zero;}; //zero capt.ed-by-ref
    //    auto is_positive = [ & ](int n){return n > zero;}; //all capt.ed vars capt.ed-by-ref
    cout << boolalpha << is_positive(-2) << endl; //with boolalpha, this prints 'false'
}

/**
 * Example where lambda prevents use of auto type, and usage of std::function.
 * http://en.cppreference.com/w/cpp/utility/functional/function
 */
void example12_lambda3_fibonacci() {
    //    auto fib = [](int n){return n < 2 ? 1 : fib(n-1)+fib(n-2);}; //error: fib not captured
    //    auto fib = [&fib](int n){return n < 2 ? 1 : fib(n-1)+fib(n-2);}; //error: auto cannot be resolved
    function<int(int)> fib = [&fib](int n) {
        return n < 2 ? 1 : fib(n - 1) + fib(n - 2);
    }; //declare as std::function instead of auto, capture fib
    
    cout << fib(8) << endl;
}