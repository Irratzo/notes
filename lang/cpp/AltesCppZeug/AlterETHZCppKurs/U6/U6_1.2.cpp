/***
 * D-ITET Informatik 1, Uebungsserie 6, Aufgabe 1.2
 *
 * Koautor: Johannes Wasmer
 * Datum: 07.11.2011
 *
 * 
 * Stack Implementation with linked list
 */

#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;


//Structs, Arrays und andere globale Variablen hier definieren.
struct node
{ int data;   //value of stack
  node *next; //Pointer to next node
};

int numberofElements = 0;
node *start_ptr = NULL;


void init() {
}

int pop(){
  //Procedure: just delete temp; i.e. delete node would break the chain.
  //So we have to reassign the pointers, then delete node at the last moment.
  //Example: delete from start:
  //node *temp; //Declare temp pointer
  //temp = start_ptr ; //make temp pointer identical to start ptr
  //start_ptr = start_ptr->next; //Set start to second node in chain.
  //delete temp; //Delete original start node.

  //Delete node from end of list:
  //temp pointer must find where end of list is by hopping along from start.
  //So it is similar to the push function.
  //We need two pointers.
  //temp1 points to last node in list.
  //temp2 points to previous node.
  //delete last node, then set next ptr of prev node to NULL (make the new last)
  //Procedure: 
  //make temp1 point to what start points to.
  //if not NULL, make temp2 point to what temp1 points to and
  //move temp1 one node forward with temp1->next (next is of current node!)
  //repeat above to lines until temp1 points to NULL
  //then delete temp1 and
  //with temp2->next = NULL make what temp2 points to the last node

  //Problem: if list only contains one node, this will give an error.
  //so: if first node eq last node (has a NULL next pointer), then
  //delete and assign start ptr to NULL. temp2 then not necesarry.

  int value =0; //for returning last value

  node *temp3, *temp4;
  temp3 = start_ptr; 

  if (start_ptr == NULL)
    { cout << "List is empty." << endl;
      delete temp3;
    }
  else if (temp3->next == NULL) {

    value = temp3->data;
    delete temp3;
    start_ptr = NULL;
    numberofElements--;

  } 

  else {
    while (temp3->next != NULL) {
      temp4 = temp3;
      temp3 = temp3->next;
    }
    value = temp3->data;
    delete temp3;
    temp4->next = NULL;
    numberofElements--;
  }
  return value;
}


void push(int element){

  node *temp, *temp2; //Temporary pointers
  temp = new node;  //declare space for pointer item, assign temp pointer to it
                    //refer to new node: *temp: "node that temp points to".
                    //(*temp).xxx refers to field of pointer, equiv. temp->xxx
  temp->data = element; //assign value to field data of pointer
  temp->next = NULL;   //When inserted in list, this node is the last node
  //Set up link to this node
  if (start_ptr == NULL) { //list is empty: start pointer to point to new node 
    start_ptr = temp; 
  }
  else {   //list !empty: 2nd pointer to step through list until last node
    temp2 = start_ptr;   //This is not NULL, because list not empty
    while (temp2->next != NULL) {
      temp2 = temp2->next;      //Move to next link in list
    }
    temp2->next = temp;
    numberofElements++;
  }
}




int size() {
  return numberofElements;
}


void clear() {
  while (numberofElements > 0) {
    pop();
  }
}


//Dieses Funktion implementiert eine Testumgebung für den Stack
void test() {
  cout << "The program has been startet without any arguments." << endl;
  cout << "The program enters the stack test mode:" << endl;
  cout << "Enter one of the commands: push, pop, show or end" << endl;
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
    } else if(command == "show") {
      //set a temporary pointer to point to the same thing as the start pointer
      node *temp;
      temp = start_ptr;
      //if pointer points to NULL, display "end of list" and stop.
      do
	{ if (temp == NULL)
	    cout << "End of list" << endl;
	  //otherwise: display details of node pointed to by start pointer.
	  else
	    { 
	      cout << temp->data << endl;
	      //Move to next node (if present)
	      //i.e. make temp ptr point to same thing as next pointer of the node it is currently indicating.
	      temp = temp->next;
	    }
	} while (temp != NULL); //do until end of list

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



