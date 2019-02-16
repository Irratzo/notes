/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   InitAndCtorInheritance_Mine.h
 * Author: johannesw
 *
 * Created on 4. Januar 2017, 15:41
 */

#ifndef INITANDCTORINHERITANCE_MINE_H
#define INITANDCTORINHERITANCE_MINE_H

#ifdef __cplusplus
extern "C" {
#endif

    /**
     * 
     * Jetbrains Tour of Modern C++ - Example 06
     * Default value initialization
     */
    class Animal {
    protected:
        int legs = 4; //Example 06: C++11 supports default value init like C#
    public:
        explicit Animal(int legs);
        /*
         * explicit keyword disallows implicit type conversion, e.g. 
         * Animal a(6);
         * a = 4; //undesired type conversion, prohibited
         * Detailed Example, see http://flo.mueckeimnetz.de/2009/10/c-schlusselwort-explicit/
         */
        virtual int walk(int steps);
        /*
         * Example 08:
         * virtual int walk(int steps) final {:
         * overriding by Human would produce compile-time error
         * thanks to C++11 final keyword
         */
    };

    /**
     * Jetbrains Tour of Modern C++ - Example 07
     * Simple constructor propagation,
     * Deleted Functions example
     */
    class Human : public Animal {
    public:

        Human() : Animal(2) {
        } //Example 07: C++11-enabled simple Constructor Propagation

        int walk(int steps) override;
        /*
         * override keyword not obligatory. but good practice since
         * some IDEs recognize a mismatch if e.g. the base function type
         * changes from int to short
         */

        //Example 09: C++11 Deleted Functions examples:
        Human(const Human &) = delete; //prohibit copy-Ctor init
        Human& operator=(const Human&) & = delete; //prohibit assignment op. overload
        /*
         * Now, Human h; Human h2{h}; is not possible anymore.
         */
    };


#ifdef __cplusplus
}
#endif

#endif /* INITANDCTORINHERITANCE_MINE_H */

