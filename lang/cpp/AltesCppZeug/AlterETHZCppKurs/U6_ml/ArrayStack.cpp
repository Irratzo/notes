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
int* data;  //Pointer auf das Array
int numberOfElements;  //Anzahl Elemente im Stack
int sizeOfArray; //Gegenwärtige Kapazität des Arrays

void init() {
  numberOfElements = 0;
  sizeOfArray = 2;
  data = new int[sizeOfArray];
}


int pop(){
  //Prüfen ob der Stack leer ist -> Fehler	
  if (numberOfElements < 1){ 
    cout << "Stack underrun: Stack is empty!" << endl;
    return -1;
  } else {
    numberOfElements--;
    return data[numberOfElements];
  }
  return 0;
}

void push(int element){
  
  // Falls Kapazität erschöpft: Neues Array erstellen
  if ( sizeOfArray <= numberOfElements){
   
    int* tempdata = new int[2 * sizeOfArray];
    for (int i = 0; i < sizeOfArray; i++){tempdata[i] = data[i];}
    sizeOfArray = 2* sizeOfArray;
    delete[] data;
    data = tempdata;
  }
  data[numberOfElements] = element;
  numberOfElements++;
}

int size() {
  return numberOfElements;	
}


void clear() {
  delete[] data;
  numberOfElements = 0;	
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



