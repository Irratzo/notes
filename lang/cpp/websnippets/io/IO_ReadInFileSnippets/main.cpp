/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: johannesw
 *
 * Created on 13. Juli 2017, 20:59
 */

#include <cstdlib>
#include "IO_ReadInTextFile.h"

using namespace std;






/*
 * 
 */
int main(int argc, char** argv) {
    
    IO_ReadInTextFile reader;
    string infile = "file.txt";
    string outfile = "file2.txt";
    
//    vector<string> lines = reader.readLines(infile); //works!
//    string content = reader.readFileIntoSingleString(infile); //works!
    
//    char* memblock = reader.readBinFile(infile); //test with bin, not with txt file
//    cout << "no of readin lines" << lines.size() << endl;
    
//    reader.writeLines(outfile,lines); //works!


    return 0;
}

