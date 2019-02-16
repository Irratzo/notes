/*
 * Simple game showcasing two Composition examples.
 * Source: http://www.learncpp.com/cpp-tutorial/102-composition/
 * 
 * First example: ObjectComposition using Point2D, Creature
 */


/* 
 * File:   main.cpp
 * Author: johannesw
 *
 * Created on 11. Juli 2017, 17:47
 */

#include <string>
#include <iostream>

#include "Creature.h"
#include "Point2D.h"

#include "Person.h"
#include "Address.h"
#include "AddressUsingVector.h"


void ex1002_objectComposition_Game();
void ex1003_aggregation();

int main() {

    //    std::cout << "-------Example 1: Object Composition -------------------" << std::endl;
    //    ex1002_objectComposition_Game();

    std::cout << "-------Example 2: Aggregation -------------------" << std::endl;
    ex1003_aggregation();



    return 0;
}

void ex1002_objectComposition_Game() {
    std::cout << "Enter a name for your creature: ";
    std::string name;
    std::cin >> name;
    Creature creature(name, Point2D(4, 7));

    while (1) {
        // print the creature's name and location
        std::cout << creature << '\n';

        std::cout << "Enter new X location for creature (-1 to quit game): ";
        int x = 0;
        std::cin >> x;
        if (x == -1)
            break;

        std::cout << "Enter new Y location for creature (-1 to quit game): ";
        int y = 0;
        std::cin >> y;
        if (y == -1)
            break;

        creature.moveTo(x, y);
    }

}

void ex1003_aggregation() {
    Person ps[3]{
        Person{"PapaBaer", 32},
        Person{"MamaBaer", 31},
        Person{"Schnuckibaer", 2}
    };
    //    std::cout << ps[0] << std::endl;

    Address a{"Leuchtkaeferstr.", 447, 88921, "Schgandznhahnde", ps, 3};
    std::cout << a;


    std::cout << std::endl << "now the same again with Person vector instead of array" << std::endl;
    std::vector<Person> ps2{
        Person{"PapaBaer", 32},
        Person{"MamaBaer", 31},
        Person{"Schnuckibaer", 2}};
    AddressUsingVector a2{"Leuchtkaeferstr.", 447, 88921, "Schgandznhahnde", ps2};
    std::cout << a2;


}



