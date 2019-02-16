/*
 * Informatik 1 D-ITET
 * Framework Serie 6, Aufgabe 2
 *
 * 26.10.2008 by Daniel Keller, Dirk Zimmer
 *
 */

#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;


//Structs, Arrays und andere globale Variablen hier definieren.


void init() {
//TODO: Code hier einfügen	
}

int pop(){
//TODO: Code hier einfügen		
}

void push(int element){
//TODO: Code hier einfügen		
}

int size() {
//TODO: Code hier einfügen	
}


void clear() {
//TODO: Code hier einfügen	
}


//Dieses Funktion implementiert eine Testumgebung für den Stack
void test() {
    cout << "The program has been startet without any arguments." << endl;
    cout << "The program enters the stack test mode:" << endl;
    cout << "Enter one of the commands: push, pop, end" << endl;
    string command;
    do{
      cin >> command;
      if (command == "pop"){
        cout << pop() << endl;
      } else if (command == "push"){
        cout << "element?";
        int elementToPush;
        cin >> elementToPush;
        push(elementToPush);
      } else if(command == "end"){
      } else {cout << "command not recognised"<< endl;};
    }while(command != "end");
}

int main(int argc, char * argv[]){

  init();	
  test();
  clear();
  return 0;

}



