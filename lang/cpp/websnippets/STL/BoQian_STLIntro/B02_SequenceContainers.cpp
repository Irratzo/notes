/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "BoQuianSTLIntro.h"

void boQuianSTL_02SequenceContainers() {

    //vec, see 01_Overview
    
    /*---------------------------deque----------------------------------------*/
    //like vec, additionally:
    deque<int> deq = {2, 3, 4};
    deq.push_front(1); //only deque
    deq.push_back(5);
    
    /*---------------------------list----------------------------------------*/

    list<int> li = {5, 7, 9};
    li.push_back(6);
    li.push_front(4); //4,5,7,9,6

    list<int>::iterator it = find(li.begin(), li.end(), 7); //it->7
    li.insert(it, 8); //4,5,*8*,7,9,6

    it++; //it->9
    li.erase(it); //4,5,8,7,6 O(1)
    //CAUTION: it is now gone, does not point to li elements anymore!
    it = find(li.begin(), li.end(), 7);


    //kill feature of list: splicing in O(1)
    list<int> li2 = {40, 41, 42, 43, 44, 45, 46};
    cout << "list1, list2 before splicing:" << endl;
    b02_printLists(li, li2);

    list<int>::iterator it2a = find(li2.begin(), li2.end(), 42);
    list<int>::iterator it2b = find(li2.begin(), li2.end(), 45);
    cout << *it2a << endl;
    cout << *it2b << endl;
    li.splice(it, li2, it2a, it2b);
    //li: 4,5,8,*42,43,44,*,7,6
    //li2: 40,41,45,46

    cout << "list1, list2 after splicing:" << endl;
    b02_printLists(li, li2);
    
    /*---------------------------array----------------------------------------*/
    //like C-array: non-dynamic, but supports other common methods
    int a[3] = {3,4,5}; //C-Array
    array<int, 3> arr = {3,4,5}; 
    //CAUTION! is of type array_int_size3!
    //An int array with 4 elements has a different type!!!
    arr.begin();
    arr.end();
    arr.size();
    //arr.swap(other-3-int-array);
    

}

template <class T>
void b02_printLists(list<T> li1, list<T> li2) {
    //template of course makes no sense since "%d" only accepts integers
    for (auto i : li1)
        printf("%2d, ", i);
    cout << endl;
    for (auto i : li2)
        printf("%2d, ", i);
    cout << endl;
}

