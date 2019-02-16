/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IO_ReadInTextFile.h
 * Author: johannesw
 *
 * Created on 13. Juli 2017, 21:06
 */

#ifndef IO_READINTEXTFILE_H
#define IO_READINTEXTFILE_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

class IO_ReadInTextFile {
    //    ifstream file("file.txt", ios::in|ios::binary|ios::ate);
    ifstream in;
    ofstream out;


public:

    /*========================READ IN=========================================*/
    /*=========================================================================*/

    /*======================Text Files========================================*/

    vector<string> readLines(string file) {
        in.open(file);
        vector<string> lines;
        string line;
        if (in.is_open()) {
            while (getline(in, line)) {
                lines.push_back(line);
            }
            in.close();
        } else {
            cout << "Unable to open file";
        }
        return lines;
    }

    string readFileIntoSingleString(string file) {
        in.open(file);
        if (in.is_open()) {
            stringstream sstr;
            sstr << in.rdbuf();
            return sstr.str();
        } else {
            cout << "Unable to open file";
            return "";
        }
    }

    //    Reading into char*:
    //
    //ifstream file ("file.txt", ios::in|ios::binary|ios::ate);
    //if (file.is_open())
    //{
    //    file.seekg(0, ios::end);
    //    size = file.tellg();
    //    char *contents = new char [size];
    //    file.seekg (0, ios::beg);
    //    file.read (contents, size);
    //    file.close();
    //    //... do something with it
    //    delete [] contents;
    //}
    //
    //Into std::string:
    //
    //std::ifstream in("file.txt");
    //std::string contents((std::istreambuf_iterator<char>(in)), 
    //    std::istreambuf_iterator<char>());
    //
    //Into vector<char>:
    //
    //std::ifstream in("file.txt");
    //std::vector<char> contents((std::istreambuf_iterator<char>(in)),
    //    std::istreambuf_iterator<char>());
    //
    //Into string, using stringstream:
    //
    //std::ifstream in("file.txt");
    //std::stringstream buffer;
    //buffer << in.rdbuf();
    //std::string contents(buffer.str());

    /*=========================Binary Files==================================*/

    int getBinFileSizeInBytes(string file) {
        int size = 0;
        streampos begin, end;
        in.open(file, ios::binary);
        if (in.is_open()) {
            begin = in.tellg();
            in.seekg(0, ios::end);
            end = in.tellg();
            in.close();
            int size = (end - begin);
        } else {
            cout << "Unable to open file, or not a binary file";
        }
        return size;
    }

    char* readBinFile(string file) {
        streampos size;
        char * memblock;

        in.open(file, ios::in | ios::binary | ios::ate);
        if (in.is_open()) {
            size = in.tellg();
            memblock = new char [size];
            in.seekg(0, ios::beg);
            in.read(memblock, size);
            in.close();
            //            cout << "the entire file content is in memory";
            //            delete[] memblock;
        } else {
            memblock = new char[0];
            cout << "Unable to open file";
        }
        return memblock;
    }


    /*========================WRITE OUT=========================================*/
    /*=========================================================================*/

    /*======================Text Files========================================*/

    void writeLines(string file, vector<string> lines) {
        out.open(file);
        if (out.is_open()) {
            for (auto &line : lines) {
                out << line;
            }
            out.close();
        } else cout << "Unable to open file";
    }






};





#endif /* IO_READINTEXTFILE_H */

