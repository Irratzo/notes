/***
 * Programm Uebung 4, Aufgabe 3
 *
 * Author: Johannes Wasmer <wasmerj@student.ethz.ch>
 * Last change: 2011/10/27
 *
 * This program uses the Vigenere-Cipher to encode an ASCII message
 * via a keyword, and deciphers it again, all on the command line.
 * The message can contain all kinds of characters.
 * ATTENTION:
 * The key only can contain [a-z] and [A-Z].
 *
 *
 */

using namespace std;

#include <iostream>
#include <string>
#include <cmath>


  //make from key new key with length of msg by appending keys
string stretchkey(string key, int msg_size) {
  int key_size = key.size();
  string ringkey;
  int factor = 0;
  int rest = 0;

  factor = msg_size/key_size;
  rest = msg_size % key_size;

  for (int i=0; i<factor; i++) {

    ringkey.append(key);

  }

  ringkey.append(key,0,rest); //append key from first char to char at position rest

  return ringkey;

}

string encode(string msg, int msg_size, string ringkey) {

  string rep; //stores one character at a time

  for (int i=0; i<msg_size; i++) {

    if (msg.at(i) >= 97 && msg.at(i) <= 122) { //lower case a-z
      rep = msg.at(i)-32; 
      msg.replace(i,1,rep); //replace one char. at pos i in msg with rep
    }
    if (ringkey.at(i) >= 97 && ringkey.at(i) <= 122) { //lower case a-z
      rep = ringkey.at(i)-32; 
      ringkey.replace(i,1,rep); //replace one char. at pos i in ringkey with rep
    }

    if (msg.at(i) < 65 || msg.at(i) > 90) continue; //if char not in A-Z

    rep = ( (msg.at(i)-65 + ringkey.at(i)-65) % 26) + 65;

    msg.replace(i,1,rep); //overwrite original

    //    cout << msg << endl; //shows process
  }
  cout << endl;
  return msg;

}

string decode (string msg, int msg_size, string ringkey) {

  string rep; //stores one character at a time


  for (int i=0; i<msg_size; i++) {

    if (ringkey.at(i) >= 97 && ringkey.at(i) <= 122) { //lower case a-z
      rep = ringkey.at(i)-32; 
      ringkey.replace(i,1,rep); //replace one char. at pos i in ringkey with rep
    }

    if (msg.at(i) < 65 || msg.at(i) > 90) continue; //if char not in A-Z

    rep = ( ( (26 + msg.at(i)-65) - (ringkey.at(i)-65)) % 26) + 65;
    msg.replace(i,1,rep); //overwrite original

    //    cout << msg << endl; //shows process
  }

  cout << endl;
  return msg;

}


int main() {

  string msg;
  string key;
  string ringkey;

  cout << "Geben Sie Ihre Nachricht ein." << endl;
  getline(cin, msg);
  int msg_size = msg.size(); //returns numbers of chars

  cout << "Schlüssel für die Verschlüsselung." << endl;
  getline(cin, key);

  //make from key new key with length of msg by appending key
  ringkey = stretchkey(key,msg_size);

  //encode
  msg = encode(msg,msg_size,ringkey);

  cout << "Die verschlüsselte Nachricht lautet. " << endl;
  cout << msg << endl;

  cout << "Schlüssel für die Entschlüsselung." << endl;
  getline(cin, key);

  ringkey = stretchkey(key,msg_size);

  //decode
  msg = decode(msg,msg_size,ringkey);

  cout << "Die entschlüsselte Nachricht lautet." << endl;
  cout << msg << endl;

  return 0;
}

