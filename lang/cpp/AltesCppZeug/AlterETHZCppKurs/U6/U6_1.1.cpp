/***
 * D-ITET Informatik 1, Uebungsserie 6, Aufgabe 1.1
 *
 * Koautor: Johannes Wasmer
 * Datum: 07.11.2011
 *
 * 
 * Stack Implementation with dynamic array
 */


#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;


//Structs, Arrays und andere globale Variablen hier definieren.


int arrsize = 2;
int numberofElements = 0;

int * data = new int[arrsize];

void init() { //this initialization makes the use of a structure necessary.

}

int pop(){
  return data[numberofElements-1];

}

void push(int element){                  //add element to stack
  if (numberofElements == arrsize) {       //resize array if too small
    int * save = new int[arrsize*2];
    for (int i = 0; i < arrsize; i++) {
      save[i] = data[i]; }
    arrsize *= 2;
    delete [] data;
    data = save;
  }
  data[numberofElements] = element;   //add element to stack
  numberofElements++;
}

int size() {
  return numberofElements;
}


void clear() {
  delete [] data;
}


//Dieses Funktion implementiert eine Testumgebung für den Stack
void test() {
  cout << "The program has been startet without any arguments." << endl;
  cout << "The program enters the stack test mode:" << endl;
  cout << "There are three commands available." << endl; 
  cout << "Once you have entered something, navigate with those commands." << endl;
  cout << "Command 1: push. Takes a value and puts it on the stack." << endl;
  cout << "Command 2: pop. Displays the last value and removes it." << endl;
  cout << "Command 3: show. Visualizes the stack." << endl;
  cout << "Command 4: end. Clears the memory and exits the program." << endl;
  cout << "Now you may enter your commands." << endl;
  string command;
  do{
    cin >> command;
    if (command == "pop"){
      if (numberofElements == 0) { cout << "Stack is empty." << endl; }
      else {cout << "Value " << pop() << " at position " << numberofElements-1 << " was removed." << endl;
	numberofElements--;}
      cout << "Please enter push, pop, show or end." << endl;
    } else if (command == "push"){
      cout << "Enter value: ";
      int elementToPush;
      cin >> elementToPush;
      push(elementToPush);
      cout << "Please enter push, pop, show or end." << endl;
    } 
    else if (command == "show") {
      cout << "The stack's size in memory is now " << arrsize << " and it looks like this." << endl; 
      cout << "Column 1 is the stack position and column 2 is its value." << endl;
      for (int k=0; k<numberofElements; k++) { 
	cout << k << "     |     " << data[k] << endl;
      }
      cout << "Please enter push, pop, show or end." << endl;
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





