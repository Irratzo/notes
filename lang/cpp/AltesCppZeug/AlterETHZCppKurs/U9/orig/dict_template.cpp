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

  // IMPLEMENT THIS
  // call create() to create a dict if NULL

}

// lookup a word in dictionary
// @param dict - dictionary
// @param word - word (suffix) to lookup
// @return true - if word was found
//         false - if word was not found
bool lookup(tnode *dict, string word){

  // IMPLEMENT THIS

}

// remove a word from dictionary
// @param dict - dictionary
// @param word - word to remove
// @return true - if word was removed
//         false - if word was not found
bool remove(tnode *dict, string word){

  // IMPLEMENT THIS
  // call is_empty(..) to check whether node has no successors

}

/********************************************************************/

// computes the number of words in dictionary
// @param - dictionary
// @return - number of words 
int num_words(tnode *dict){

  // IMPLEMENT THIS

}

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

  // IMPLEMENT THIS

}

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

  // IMPLEMENT THIS 
  // call print_rec to print list of completions if prefix found

}

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


