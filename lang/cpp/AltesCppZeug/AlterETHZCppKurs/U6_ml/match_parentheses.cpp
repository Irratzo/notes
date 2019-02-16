/*
 * Informatik 1 D-ITET
 * Framework Serie 6, Aufgabe 2
 *
 * Source code - Test a given expression for correct parentheses matching, 
 * using a stack (implented with pointers).
 *
 * Xenofon Floros
 * ML Group, ETHZ
 * 10.10.2009
 *
 */

#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;


/* THIS PART IS ALMOST THE SAME AS LAST YEAR - STACK IMPLEMENTATION
   The only difference in each element I save strings and not integers */

//Structs, Arrays und andere globale Variablen hier definieren.
struct item{
    char key; 	// Value of the element (character)	
    item*  next;   // Pointer to the next element
  };


  item* first; //Pointer auf oberstes Stapelelement
  int numberOfElements;

void init() {
  first = NULL;
  numberOfElements = 0;
}

char pop(){
  char result;
  if (first != NULL){
    item* temp = first;
    result = first->key;
    first = first -> next;
    delete temp; //nicht vergessen: Altes Element löschen.
    numberOfElements--;
  }else{  //Stack ist leer -> Fehler
    result = '$';
  }
  return result;
}


void push(char element){
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


// Main function

int main(int argc, char * argv[]){

  	  init(); //Stack initialisieren

      int stackSize;
	  int currentChar = 0;
      bool matching = true; 
	  
      char current_open;  // Current expected parenthesis/bracket
      char current_input;	  // Current inputed parenthesis/bracket
      char temp;
      
	  string inputExpression = argv[1]; 
	  int expressionLength = inputExpression.length();
	  // Loop over the characters of the expression
	  
	  cout << "Input Expression : "<< inputExpression << endl;
	  cout << "Length = " << expressionLength << endl;
	      
      while (currentChar < expressionLength) {
                 
         current_input = inputExpression[currentChar];
           
	    //If you encounter an opening parenthesis push it in the stack
	    if ( current_input == '(' )
	       push('(');
        else if ( current_input == '{'  )
           push('{');
        // If you encounter a closing parenthesis pop 
        else if ( current_input == ')' ){
             current_open = pop();
             if ( current_open != '(' ){
                matching = false;
                break;
             }
        }
        else if ( current_input == '}' ){
             current_open = pop();
             if ( current_open != '{'){
                matching = false;
                break;
             }
        }    
        
        currentChar++;
	  }	  // END OF LOOP 
	    
	    
	  temp = pop();

	  // If there are still elements in the stack
	  if ( temp != '$' ) {	  	 			
	  	 			
	  	 if (matching) {
		 	cout << temp << " was not closed at all";
            cout << endl;
            cout << "Parentheses do not match" << endl;		   
         }
         else {
		  	cout << current_open << " has opened, but closing " << current_input << " encountered !";
	        cout << endl;
	        cout << "Parentheses do not match" << endl; 		    
	     }
       }
	   // If there are no more elements in the stack everything has been closed
	   // one way or the other 
	   else {
	   		if (matching)
	             cout << "Parentheses match OK !!" << endl;
    		else{
            	 cout << current_open << " opened, but closing " << current_input << " encountered !";
	        	 cout << endl;
	         	 cout << "Parentheses do not match" << endl;
   		    }	
	   }					  
           

	  clear(); //Empty stack
	  
	  return 0;

}



