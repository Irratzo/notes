//
// Informatik I (D-ITET), HS 2009
// Uebung 9.1 -- Woerterbuch mit Trie Datenstruktur
//
// Author: Ch. Sprenger
//

#include <iostream>
#include <string>
#include "dict.h"

/********************************************************************/

//
// checks whether dict node has no successors
// @param dict - dictionary node (must be non-NULL!)
// @return true - iff node has no outgoing edges
//
bool is_empty(tnode *dict){
  int i = 0;
  while (i < N && dict->edges[i] == NULL){
    i = i + 1;
  }
  return (i >= N);
}

/********************************************************************/

//
// create and initalize a fresh dict node
// @return tn - the new dict node
//
tnode *create(){
  tnode *tn = new tnode;
  int i;
  for (i = 0; i < N; i = i + 1){
    tn->valid = false;
    tn->edges[i] = NULL;
  }
  return tn;
}

//
// insert a word into the dict dictionary
// @param dict - dictionary
// @param word - current word
// @return true - if word was inserted
//         false - if word was already there
// 
bool insert(tnode *dict, string word){
  if (dict == NULL) {
    tnode *dict = create();
  }
  
  else if (word == "") {           //recursion aborts if true
    if (dict->valid) {        //if word is already in trie
      return false;
    }
    else {
      dict->valid = true;
      return true;
    }
  }
  else {
    int i = (int)word[0];        //find appropriate edge of each string char.
    if (dict->edges[i] == NULL){ //if no nodes found for those:
      dict->edges[i] = create(); //create them.
    }                            
    return insert(dict->edges[i], word.substr(1));
    //call insert recursion for children nodes and the first substring 
    //of the word (valid). (Recursivity ensures alphabetical order)
  }
}

  // IMPLEMENT THIS
  // call create() to create a dict if NULL


// lookup a word in dictionary
// @param dict - dictionary
// @param word - word (suffix) to lookup
// @return true - if word was found
//         false - if word was not found
bool lookup(tnode *dict, string word){
  if (dict == NULL) {
    return false; 
  }
  else if (word == "") {
    return dict->valid;
  }
  else {                   //look recursively at successor nodes, follow path
    int i = (int)word[0];  //until either word is found or not
    return lookup(dict->edges[i], word.substr(1));
  }
}
  // IMPLEMENT THIS



// remove a word from dictionary
// @param dict - dictionary
// @param word - word to remove
// @return true - if word was removed
//         false - if word was not found
bool remove(tnode *dict, string word){
  if (dict == NULL) {        //only prefix of word in dict
    return false;           //not in dict
  }
  else if (word == "") {
    if (dict->valid) {     //word found
      dict->valid = false; //delete node
      return true;         //word removed
    }
    else {                //prefix found, but not a valid word
      return false;       //some other word found; dont delete anything
    }
  }
  else {
    /* recursively look if word is in dictionary. if found, start cleaning up 
       space (delet[]), set pointers to NULL.
    */
    int i = (int)word[0];        //find appropriate edge of each string char.
    bool found = remove(dict->edges[i],word.substr(1));
    //    if (found && dict->valid) {
    if (found && !dict->valid) {
      if (is_empty(dict->edges[i])) {
	  delete dict->edges[i];
	  dict->edges[i] = NULL;
	}
	} return found;
      /* Also use fct is_empty() to check if node has no successors.
	 Cannot delete node when other words depend on it*/
    }
}
  // IMPLEMENT THIS
  // call is_empty(..) to check whether node has no successors
  


/********************************************************************/

// computes the number of words in dictionary
// @param - dictionary
// @return - number of words 
int num_words(tnode *dict){
  if (dict == NULL) {
    return 0;
  }
  else {
    int i = 0;
    //int n = 1;
    int k = (int)dict->valid;
    
    for (int i = 0; i < N; i++){
      k += num_words(dict->edges[i]);
    }
    return k;
  }
}
  // IMPLEMENT THIS



// counts the number of nodes in dict 
// @param - dictionary
// @return - number of nodes
int num_nodes(tnode *dict){
  if (dict == NULL){
    return 0;
  } else {
    int i = 0;
    int n = 1;

    for (i = 0; i < N; i = i + 1){
      n = n + num_nodes(dict->edges[i]);
    }
    return n;
  }
}

/********************************************************************/

// print sorted dictionary 
// @param dict - dictionary
// @param word - word (prefix) at current node
//
void print_rec(tnode *dict, string prefix){
  //print, print_similar call this fct;
  //helper fcts (*_rec) have additional arguments not to be passed main fct.
  if (dict == NULL) {
    return;
  }
  else {
    if (dict->valid) {          //print recursively updated string at word node
      cout << prefix << endl;
    }
    for (int i=0; i<N; i++) {   //recurse through nodeds
      print_rec(dict->edges[i], prefix+(char)i);
    }    //+ here overloaded operator for string class, concatenates
  }
}
// IMPLEMENT THIS


void print(tnode *dict){
  print_rec(dict, "");
}

// prints all dictionary entries with given prefix
// @param dict - dictionary
// @param prefix - prefix of original word
// @param suffix - suffix of original word 
// @return true - iff orignal word is a valid entry in dictionary
//
bool print_completion_rec(tnode *dict, string prefix, string suffix){
  // call print_rec to print list of completions if prefix found
  if (dict == NULL) {
    return false;
  }
  /*  else if (suffix == "") {    //if no completions
      if (dict->valid) {   //
      //  dict->valid = false; //
      return true;         //
      }*/
  else {
    if (suffix == "") {
      print_rec(dict, prefix);
      return true;
    }
    else {
      for (int i=0; i<N; i++) {   //recurse through nodes
	print_rec(dict->edges[i], prefix+(char)i);
	//return false;
      }
    }    
  }
}
// IMPLEMENT THIS 




bool print_completion(tnode *dict, string word){
  return print_completion_rec(dict, "", word);
}

// prints all words that are similar to given word
// i.e. determines maximal word prefix that is present in
// dictionary and prints all words with the same prefix
// @param dict - dictionary
// @param prefix - prefix of original word
// @param suffix - suffix of original word 
// @return true - iff orignal word is a valid entry in dictionary
//
bool print_similar_rec(tnode *dict, string prefix, string suffix){

  // IMPLEMENT THIS 
  // call print_rec to print list of similar words
}

bool print_similar(tnode *dict, string word){
  return print_similar_rec(dict, "", word);
}

// print dictionary as a tree (mainly for debugging)
// @param dict - dictionary
// @param level - current distance from root + 1
//
void print_tree_rec(tnode *dict, int level){
  if (dict != NULL){
    int i = 0;
    for (i = 0; i < N; i = i + 1){
      if (dict->edges[i] != NULL){
	cout.width(3 * level);
        cout << (char)i;
        if (dict->edges[i]->valid) 
          cout << "*" << endl;
        else 
          cout << " " << endl;
        print_tree_rec(dict->edges[i], level + 1);
      }
    }
  }
}

void print_tree(tnode *dict){
  print_tree_rec(dict, 1);
}


