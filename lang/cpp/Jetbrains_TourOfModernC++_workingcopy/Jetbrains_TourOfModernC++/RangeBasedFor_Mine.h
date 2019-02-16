/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RangeBasedFor_Mine.h
 * Author: johannesw
 *
 * Created on 4. Januar 2017, 18:55
 */

#ifndef RANGEBASEDFOR_MINE_H
#define RANGEBASEDFOR_MINE_H

//<< Overloading for generic cout-ing a vector like "cout << v", see examples (bottom)
template <typename T>
ostream& operator<<(ostream& out, const vector<T>& coll);
void example15_forLoopCompendium_sequenceContainer();

void example16_forLoop_KVContainer();


#endif /* RANGEBASEDFOR_MINE_H */

