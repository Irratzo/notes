 /*
 * Informatik 1 D-ITET HS10
 * Group Floros
 * Student Johannes Wasmer
 * Ubung 6.2
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

void pop(){
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

  //char value; //for returning last bracket

  node *temp3, *temp4;
  temp3 = start_ptr; 

  /* if (start_ptr == NULL)
     { 
     //      value = '0';
     cout << "List is empty." << endl;
     delete temp3;
     }
     else */ if (temp3->next == NULL) {

    //  value = temp3->data;
    delete temp3;
    start_ptr = NULL;
    //numberofElements--;

  } 

  else {
    while (temp3->next != NULL) {
      temp4 = temp3;
      temp3 = temp3->next;
    }
    //value = temp3->data;
    delete temp3;
    temp4->next = NULL;
    //     numberofElements--;
  }
  //return value;
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
    //    numberofElements++;
  }
}




int size() {
  return numberofElements;
}


void clear() {
  //do pop() beginning from last node until first node
  while (numberofElements > 0) {
    pop();
  }
}


int main(int argc, char * argv[]){

  char topush; //Opening Bracket that is being (reversed-)pushed onto the stack
  //a variable for pop() is therefore unnecessary, if arg not starts with closing br.
  char compare; //closing bracket from pop() to compare with pushed one.
  string arg = argv[1]; //convert argv[1] to string to get arg length
  int arglength = arg.length(); //# characters of argument
  char reading; //current input character in loop over argument
 
  
  for (int i=0; i<arglength; i++) {

    reading = arg[i]; //ISO C++ forbids comparison between pointer and integer
    //with argv[i]: invalid conversion from 'char*' to 'char'
    
    /*for testing   
      cout << numberofElements << endl;
      cout << reading << endl;
    */

    if (reading == '(' ) {         //if current character either (
      topush = ')'; //then push ) to stack
      push(topush);
      numberofElements++;
    }
    else  if (reading == '{' ) {         //if current character {
      topush = '}'; //then push } to stack accordingly
      push(topush);
      numberofElements++;
    }
    else if (reading == ')') {   //if current character either ) or } 

      /*for testing 
	cout << "test" << endl;
      */

      compare = ')'; //then store it accordingly in compare
      pop();
      //topush = pop(); //remove last pushed bracket. (actually, topush == pop() !)
      numberofElements--;
      if (compare != topush) {  //if last closing doesnt match last opening bracket
	//	if (compare == ')' ) {  //if last closing bracket was )
	cout << "{ has opened, but closing ) encountered." << endl;
	cout << "Brackets do not match." << endl;
	cout << "Positions: " << numberofElements << ". opening and " << i << ". closing bracket." << endl;
	break;
      }
    }
    else if (reading == '}') {   //if current character either ) or } 
      compare = '}'; //then store it accordingly in compare
      pop();
      // topush = pop(); //remove last pushed bracket. (actually, topush == pop() !)
      numberofElements--;
      if (compare != topush) {                   //if last closing bracket was }
	cout << "( has opened, but closing } encountered." << endl;
	cout << "Brackets do not match." << endl;
	cout << "Positions: " << numberofElements << ". opening and " << i << ". closing bracket." << endl;
	break;
      }
    }
    else {}    
  }


 
  /*for testing the alternative forloop  below
    cout << reading << endl;
    cout //<< arg[0]
    << arg[1]
    << arg[2] << endl;
    cout << arglength << numberofElements << endl;
  */    
  /* alternative loop content; does also not work

     if (reading == ('(' || '{') ) {         //if current character either ( or {
     topush = reading == '(' ? ')' : '}'; //then push ) or } to stack accordingly
     push(topush);
     numberofElements++;
     }
     else if (reading == (')' || '}') ) {   //if current character either ) or } 
     compare = reading == ')' ? ')' : '}'; //then store it accordingly in compare
     topush = pop(); //remove last pushed bracket. (actually, topush == pop() !)
     numberofElements--;
     if (compare != topush) {  //if last closing doesnt match last opening bracket
     if (compare == ')' ) {  //if last closing bracket was )
     cout << "{ has opened, but closing ) encountered." << endl;
     cout << "Brackets do not match." << endl;
     cout << "Positions: " << numberofElements << ". opening and " << i << ". closing bracket." << endl;
     break;}
     }
     else {                   //if last closing bracket was }
     cout << "( has opened, but closing } encountered." << endl;
     cout << "Brackets do not match." << endl;
     cout << "Positions: " << numberofElements << ". opening and " << i << ". closing bracket." << endl;
     break;
     }
     }
      
  
     else {}
     }
  */   


  //if loop has run through, check if #opening matches #closing brackets
  if (numberofElements != 0) { //if #popped != #pushed there must be unclosed bracket
    topush = start_ptr->data == ')' ? '(' : '{'; //store it in topush
    cout << topush << " not closed at all!" << endl; 
    cout << "Brackets do not match." << endl;
  }
  else {
    cout << "Brackets match is OK. Congratulations!" << endl;
  }

  clear();
  return 0;

}



