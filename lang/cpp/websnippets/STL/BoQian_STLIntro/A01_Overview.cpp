/*
 * Source: https://www.youtube.com/watch?v=ltBdTiRgSaw
 */

#include "BoQuianSTLIntro.h"

void boQuianSTL_01Overview(){
    
    vector<int> vec;
    vec.push_back(4);
    vec.push_back(1);
    vec.push_back(8);
    
    vector<int>::iterator itr1 = vec.begin(); //half-open: [begin, end)
    vector<int>::iterator itr2 = vec.end();
    //NOTE: this means: end() is nextel OUTSIDE container, so ALWAYS stop ONE BEFORE it!
    // cout << *vec.end(); OUCH! Outside container!
    
    for (vector<int>::iterator itr = itr1; itr!=itr2; ++itr)
        cout << *itr << " "; //4 1 8
    cout << endl;
    sort(itr1,itr2); //1 4 8
}


