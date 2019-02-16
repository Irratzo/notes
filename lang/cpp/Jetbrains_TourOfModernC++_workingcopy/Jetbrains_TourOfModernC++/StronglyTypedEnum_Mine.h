/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StronglyTypedEnum_Mine.h
 * Author: johannesw
 *
 * Created on 4. Januar 2017, 18:32
 */

#ifndef STRONGLYTYPEDENUM_MINE_H
#define STRONGLYTYPEDENUM_MINE_H

/**
 * Note: this enum is now publicly available if this file is included.
 */
enum OldColor {
    Red, Green, Blue
};

enum class NewColor {
    Red, Green, Blue, Magenta
};


void example13_oldEnums();
void example14_newEnums1();

#endif /* STRONGLYTYPEDENUM_MINE_H */

