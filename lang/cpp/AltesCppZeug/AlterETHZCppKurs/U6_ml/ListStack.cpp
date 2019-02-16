/*
 * Informatik 1 D-ITET
 * Framework Serie 6, Aufgabe 2
 *
 * 11.11.2008 by Daniel Keller, Dirk Zimmer
 *
 */

#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;


//Structs, Arrays und andere globale Variablen hier definieren.
struct item{
    int key; //Wert des Stackelements
    item*  next;  //Pointer zum unteren Element
  };


  item* first; //Pointer auf oberstes Stapelelement
  int numberOfElements;

void init() {
  first = NULL;
  numberOfElements = 0;
}


int pop(){
  int result;
  if (first != NULL){
    item* temp = first;
    result = first->key;
    first = first -> next;
    delete temp; //nicht vergessen: Altes Element löschen.
    numberOfElements--;
  }else{  //Stack ist leer -> Fehler
    cout << "Stack underrun: Stack is empty!" << endl;
    result = -1;
  }
  return result;
}


void push(int element){
  item* ni = new item; 
  ni->key = element;
  ni->next = first;
  first = ni;
  numberOfElements++;
}


int size() {
  return numberOfElements;	
}


void clear() {
  while (numberOfElements > 0) pop(); // Den Stack leer poppen.
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



