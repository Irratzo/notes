/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * 
 * Example of using the index operator [] to realize a key-value access
 * to book contents where key is of type string instead of int.
 * Source: RRZN C++ 4.12 Special Operators
 * 
 * File:   main.cpp
 * Author: johannesw
 *
 * Created on 7. Juli 2017, 11:58
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Book {
public:
    const string& operator[](const char*) const;

    /*Ctor with parameters*/
    Book(string toc, string editorial, string index) :
    toc(toc), editorial(editorial), index(index) {
    } //Ctor

    void setChapters(vector<string>);

    int getNumChapters() const {
        return chapters.size();
    }


private:
    string toc;
    string editorial;
    vector<string> chapters;
    string index;
    string empty = "";

};

const string& Book::operator[](const char* key) const {
    string ch = "chapter";
    int indexOfChapterContent = ((string) key).find(ch, 0); //EXPRESSION

    /*
     * Note on SegFault:
     * original code used string chapter[] instead vector<string> chapter.
     * This method threw segfault when content == "chapter1" even though it existed.
     * BUT it turned out, that the SegFault had quite a different cause:
     * If the conditional marked HERE (see below) did hold the expression
     * marked EXPRESSION (see above), code throws segfault.
     * If the EXPRESSION is evaluated before if-else, however, everything 
     * works finde. Something to do with pointers and const types I guess.
     * 
     * Reason: no idea.
     */

    if (key == "toc") {
        return toc;
    } else if (key == "editorial") {
        return editorial;
    } else if (key == "index") {
        return index;
    } else if (indexOfChapterContent > -1) { //HERE, see above
        int startNo = ((string) key).find(ch, 0) + ch.length();
        int charsToEnd = ((string) key).length() - startNo;
        string chapNoStr = ((string) key).substr(startNo, charsToEnd);
        if (!chapNoStr.empty()) {
            int chapNo = stoi(chapNoStr) - 1; //stoi: C++11!
            if (-1 < chapNo && chapNo < chapters.size()) {
                return chapters[chapNo];
            }
        }
    }
    
    cout << "key not found" << endl;
    //if key not found
    return empty;
    //Note: returning "" or string empty = ""; return empty; 
    //throws a SegFault. Only declaring the empty string as class attribute
    //and returning that here did not throw SegFault. Why?

}

void Book::setChapters(vector<string> chapters) {

    /*element-wise copy works*/
    for (auto ch : chapters) {
        this->chapters.push_back(ch);
    }

    /*this throws segfault*/    
//    copy(chapters.begin(), chapters.end(), this->chapters.begin());
    
    
    /*cbv (calling CCtor internally) fails*/
//    this->chapters = chapters;
    //using this instead of the push_back results in chaper staying
    //an empty vector.

}

Book createBook(); //Note: Book& makes no sense: linked-to instance destroyed
//when function scope ends, so would return segfault
void printBookInfo(Book &b);

/*
 * 
 */
int main(int argc, char** argv) {

    Book b = createBook();
    printBookInfo(b);


    return 0;
}

Book createBook() {
    Book b("Table of Contents", "This is the Editorial", "This is the Index");
    vector<string> chapters = {"Chapter 1: Flight Through the Night",
        "Chapter 2: The Long-Lost Friend",
        "Chapter 2: An Unequivocal Message",
        "Chapter 3: The Poisoned Pickles",
        "Chapter 4: Safe at Last?"}; //C++11 initialization list
    b.setChapters(chapters);
    return b;

}

void printBookInfo(Book &b) {
    cout << "Book Contents:" << endl;
    cout << b["toc"] << endl;
    cout << b["editorial"] << endl;
    cout << "Chapters: " << endl;
    for (int i = 1; i <= b.getNumChapters(); i++) {
        const char* key = ("chapter" + to_string(i)).c_str();
        cout << b[key] << endl; //C++11
    }
    cout << b["index"] << endl;
    cout << b["nonexistingkey"] << endl;

}

