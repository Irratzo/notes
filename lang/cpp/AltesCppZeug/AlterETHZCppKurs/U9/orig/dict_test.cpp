//
// Informatik I (D-ITET), HS 2009
// Testprogramm fuer Woerterbuch
//
// Author: Ch. Sprenger
//

#include <iostream>
#include <string>
#include "dict.h"

using namespace std;

const string stop = "_STOP_";

const string word_list[] = {
  "tee",
  "teetasse", 
  "velo", 
  "velokurier", 
  "veloziped", 
  "teer",  
  "terasse",  
  "pizza", 
  "piazza", 
  "pizzaiolo",
  stop
};

int main(){
  tnode *dict = create();
  string cmd, word;
  
  do {
    cout << "[dict]$ ";
    getline(cin, cmd);   
    if (cmd == "load"){
      int i = 0;
      for (; word_list[i] != stop; i = i + 1){
        insert(dict, word_list[i]);
      }
    } else if (cmd == "insert"){
      cout << "word? ";
      getline(cin, word);
      if (insert(dict, word)){
	cout << "-> word inserted." << endl;
      }else{
	cout << "-> word already in dictionary." << endl;
      }
    } else if (cmd == "lookup"){
      cout << "word? ";
      getline(cin, word);
      if (lookup(dict, word)){
        cout << "-> word found." << endl;
      }else{ 
	cout << "-> word NOT found" << endl;
      }
    } else if (cmd == "remove"){
      cout << "word? ";
      getline(cin, word);
      if (remove(dict, word)){
        cout << "-> word removed." << endl;
      } else {
	cout << "-> word NOT found." << endl; 
      }
    } else if (cmd == "words"){
      cout << "Number of words: " << num_words(dict) << endl;
    } else if (cmd == "nodes"){
      cout << "Number of nodes: " << num_nodes(dict) << endl;
    } else if (cmd == "print"){
      print(dict);
    } else if (cmd == "complete"){
      cout << "word? ";
      getline(cin, word);
      cout << "Auto-completion list for " << word << ":" << endl;
      if (print_completion(dict, word)){
        cout << "-> word found." << endl;
      }else{
        cout << "-> word NOT found." << endl; 
      }
     } else if (cmd == "similar"){
      cout << "word? ";
      getline(cin, word);
      cout << "Similar words for " << word << ":" << endl;
      if (print_similar(dict, word)){
        cout << "-> word found." << endl;
      }else{
        cout << "-> word NOT found." << endl;
      }
    } else if (cmd == "tree"){
      print_tree(dict);
    } else if (cmd != "quit" && cmd != "") {
      cout << "Available commands: " << endl;
      cout << "  load     -- load default dictionary" << endl;
      cout << "  insert   -- insert word" << endl;
      cout << "  lookup   -- lookup word" << endl; 
      cout << "  remove   -- remove word" << endl;
      cout << "  words    -- number of words in dictionary" << endl;
      cout << "  nodes    -- number of dict nodes in dictionary" << endl;
      cout << "  print    -- print dictionary" << endl;
      cout << "  complete -- display words with given prefix" << endl;       
      cout << "  similar  -- display similar words" << endl;      
      cout << "  tree     -- print dict in tree form" << endl;
      cout << "  quit     -- quit program" << endl; 
    }
    //    cout << "------------------------------------------------------------" << endl;
  } while (cmd != "quit");

  cout << "-> Tschuess! <-" << endl;
  return 0;
}
