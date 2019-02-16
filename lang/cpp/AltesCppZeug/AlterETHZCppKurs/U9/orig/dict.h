//
// Informatik I (D-ITET), HS 2009
// Uebung 9.1 -- Woerterbuch mit Trie Datenstruktur
//
// Author: Ch. Sprenger
//

#ifndef DICT_H
#define DICT_H

using namespace std;

// maximal number of successors
const int N = 256;


// dict node with fields:
//  valid - true if character sequence up to node is a valid word
//  next - potentially N successor nodes
struct tnode {
  bool valid;
  tnode *edges[N];
};


// create and initalize a fresh dict node
// sets the valid field to false and all edges to NULL
// @return tn - new dict node, constitutes an empty dictionary
tnode *create();


// insert a word into the dict dictionary
// @param dict - dictionary (must be non-NULL!)
// @param word - current word
// @return true - if word was inserted
//         false - if word already present
bool insert(tnode *dict, string word);


// lookup a word in dictionary
// @param dict - dictionary
// @param word - word (suffix) to lookup
// @return true - if word was found
//         false - if word was not found
bool lookup(tnode *dict, string word);


// remove a word from dictionary
// the last node is never removed from the dictionary
// @param dict - dictionary
// @param word - word to remove
// @return true - if word was removed
//         false - if word was not found
bool remove(tnode *dict, string word);


// compute the number of words in dictionary
// @param - dictionary
// @return - number of words 
int num_words(tnode *dict);


// counts the number of nodes in dict 
// @param - dictionary
// @return - number of dict nodes
int num_nodes(tnode *dict);


// print sorted dictionary 
// @param dict - dictionary
void print(tnode *dict);


// prints all words in dictionary with given prefix
// @param dict - dictionary
// @param word - word to macth
// @return true - iff word is a valid entry in dictionary
bool print_completion(tnode *dict, string word);


// prints all words that are similar to given word
// i.e. determines maximal word prefix that is present in
// dictionary and prints all words with the same prefix
// @param dict - dictionary
// @param word - word to match
// @return true - iff word is a valid entry in dictionary
bool print_similar(tnode *dict, string word);


// print dictionary as a tree (for debugging)
// word ends are marked with a '*'
// @param dict - dictionary
void print_tree(tnode *dict);


#endif
