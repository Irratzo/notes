/*
 * Example of SinglyLinkedList.
 * Inspiration from "Beispielprogramme C++", Christian Forster, ETHZ, 2007.
 * The original used struct for nodes and int for values.
 * This version uses a class template.
 * ----------------------------------------------------
 * 
 * LESSONS LEARNED:
 * 1. TemplateClass: memberFct definitions INSIDE HEADER, NOT inside CPP. 
 *    Else compiler error: "undefined reference"
 * 2. memberFct add, addRec:
 *   - can't use uniformInit for setting value, need copyInit instead 
 * 
 */

/* 
 * File:   LinkedListETHZ.h
 * Author: johannesw
 *
 * Created on 13. Juli 2017, 10:47
 */

#ifndef LINKEDLISTETHZ_H
#define LINKEDLISTETHZ_H
#include <cstddef>
#include <algorithm>
#include <iostream>
using namespace std;

template <typename T>
class LinkedListETHZ {
    unsigned int size = 0;
    T value;
    LinkedListETHZ<T> *next = nullptr;

    void addRec(LinkedListETHZ<T> *&node, T value);
public:
    void add(T value);

    int getLength() {
        return static_cast<int> (size);
    }

    T getSumOfValues();

    /*overload of operator+, += for writing e.g. 'list+=5...' */
    LinkedListETHZ<T>& operator+=(T value);

    //    /*overload of operator+ for writing 'list = list + 2...' */
    //    friend LinkedListETHZ<T> operator+(LinkedListETHZ<T> lhs, const T& rhs);

    //    /*overload operator=, together with +, for writing list = list+5*/
    //    LinkedListETHZ<T>& operator=(LinkedListETHZ<T> rhs);
    //    /* operator= HAS to be memberFct: unaryOperator */


};

template <typename T>
T LinkedListETHZ<T>::getSumOfValues() {
    T sum = value;
    LinkedListETHZ<T> *current = next;
    int revCount = getLength() - 1;
    while (revCount > 0){
        sum += next->value;
        current = next->next;
        revCount--;
    }
    return sum;
}

template <typename T>
void LinkedListETHZ<T>::add(T value) {
    if (!next) {
        this->value = value;
        next = new LinkedListETHZ<T>{};
    } else {
        addRec(next, value);
    }
    size++;
}

template <typename T>
void LinkedListETHZ<T>::addRec(LinkedListETHZ<T> *&node, T value) {
    if (!(node->next)) {
        node->value = value;
        node->next = new LinkedListETHZ<T>{};
    } else {
        addRec(node->next, value);
    }
}

/*overload of operator+, += for writing e.g. 'list+=5...' */
template <typename T>
LinkedListETHZ<T>& LinkedListETHZ<T>::operator+=(T value) {
    // actual addition of rhs to *this
    add(value);
    return *this;
}

///*overload of operator+ for writing 'list = list + 2...' */
//template <typename T>
//inline LinkedListETHZ<T> LinkedListETHZ<T>::operator+(LinkedListETHZ<T> lhs, const T& rhs) {
//    lhs += rhs;
//    return lhs;
//}

///*overload operator=, together with +, for writing list = list+5*/
//template <typename T>
//LinkedListETHZ<T>& LinkedListETHZ<T>::operator=(LinkedListETHZ<T> rhs) {
//    std::swap(rhs); //C++11: <utility>, prior: <algorithm>
//    return *this;
//}





#endif /* LINKEDLISTETHZ_H */

