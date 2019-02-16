/***
 * D-ITET Informatik 1, Uebungsserie 6, Aufgabe 2
 *
 * Koautor: Johannes Wasmer
 * Datum: 09.11.2011
 *
 * 
 * Bracket matching with linked list
 */

#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;


//Structs, Arrays und andere globale Variablen hier definieren.
struct node
{ char data;   //value of stack
  node *next; //Pointer to next node
};

int numberofElements = 0;
node *start_ptr = NULL;


void init() {
}

char pop(){
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
  //We need to pointers.
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

  char value; //for returning last bracket

  node *temp3, *temp4;
  temp3 = start_ptr; 

  if (temp3->next == NULL) {

    value = temp3->data;
    delete temp3;
    start_ptr = NULL;


  } 

  else {
    while (temp3->next != NULL) {
      temp4 = temp3;
      temp3 = temp3->next;
    }
    value = temp3->data;
    delete temp3;
    temp4->next = NULL;

  }
  return value;
}


void push(char element){

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

  }
}




int size() {
  return numberofElements;
}


void clear() {
  //do pop() beginning from last node until first node
  char tmp;
  while (numberofElements > 0) {
    tmp = pop();
    numberofElements--;
  }
}


int main(int argc, char * argv[]){

  char topush; //Opening Bracket that is being (reversed-)pushed onto the stack
  //a variable for pop() is therefore unnecessary, if arg not starts with closing br.
  char compare; //closing bracket from pop() to compare with pushed one.
  string arg = argv[1]; //convert argv[1] to string to get arg length
  int arglength = arg.length(); //# characters of argument
  char reading; //current input character in loop over argument
  char popped; //store popped char
  int bcount1 = 0; //() counter
  int bcount2 = 0; //{}counter
  bool nomatch = false; //for evennumbered nomatchings
 
  
  for (int i=0; i<arglength; i++) {

    reading = arg[i]; 

    if (reading == '(' ) {         //if current character either (
      topush = ')'; //then push ) to stack
      push(topush);
      numberofElements++;
      bcount1++;
    }
    else  if (reading == '{' ) {         //if current character {
      topush = '}'; //then push } to stack accordingly
      push(topush);
      numberofElements++;
      bcount2++;
    }
    else if (reading == ')') {   //if current character either ) or } 
      bcount1++;
      compare = ')'; //then store it accordingly in compare
      popped = pop(); //remove last pushed bracket. 
      numberofElements--;
      if (compare != popped) {  //if last closing doesnt match last opening bracket
	nomatch = true;
	cout << "{ has opened, but closing ) encountered." << endl;
	cout << "Brackets do not match." << endl;
	cout << "Positions: " << numberofElements + 1 << ". opening and " << i + 1<< ". closing bracket." << endl;
	break;
      }
    }
    else if (reading == '}') {   //if current character either ) or } 
      bcount2++;
      compare = '}'; //then store it accordingly in compare
      popped = pop(); //remove last pushed bracket. 
      numberofElements--;
      if (compare != popped) {                  //if last closing bracket was }
	nomatch = true;
	cout << "( has opened, but closing } encountered." << endl;
	cout << "Brackets do not match." << endl;
	cout << "Positions: " << numberofElements + 1 << ". opening and " << i + 1 << ". closing bracket." << endl;
	break;
      }
    }
    else {}    
  }


  if ( ((bcount1 % 2) && !(bcount2 % 2)) || (!(bcount1 % 2) && (bcount2 % 2)) ) { //must be unclosed bracket, XOR

    if ( (popped == ')') && ((bcount1 % 2) != 0) )
      cout << "'(' not closed at all!" << endl; 
    else
      cout << "'{' not closed at all!" << endl; 

    cout << "Brackets do not match." << endl;
  }

  else if (nomatch == false) {
    cout << "Brackets match is OK. Congratulations!" << endl;
  }
  else {};

  clear();
  return 0;

}



