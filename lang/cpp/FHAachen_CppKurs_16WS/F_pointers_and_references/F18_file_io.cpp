/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Dateien einlesen und schreiben
 * 
 *  Stichworte:
 *      - fopen, fclose, fgetc, fscanf, getline
 *      - stream, ifstream, ofstream
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <unistd.h>

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

#include "../tools/tools.h"

void copyFileCharByChar(const char* FileSrc, const char* FileCopy)
{
	tools_log(); printf("copy %s to %s ... ",FileSrc,FileCopy);	

    FILE *fileR = fopen(FileSrc,"r"), 
         *fileW = fopen(FileCopy,"w");
         
    if (NULL!=fileR && NULL!=fileW)
    {
        int c;
        while ( (c=fgetc(fileR))!=EOF )     // read char by char
            fprintf(fileW,"%c",c);
    }

    if (NULL!=fileR)                        // close both files
        fclose(fileR);
    if (NULL!=fileW)
        fclose(fileW);
    
    printf("done \n\n");
}

void countWords(const char* FileSrc)
{
	tools_log(); printf("count words in %s: ",FileSrc);	

    FILE *fileR = fopen(FileSrc,"r");
    int words = -1;
    
    if (NULL!=fileR)
    {
        words = 0;
        char line[21];
        while ( fscanf(fileR,"%20s",line)!=EOF ) 
            ++words;
        fclose(fileR);
    }
    
    printf("%d \n\n",words);
}

void countLines(const char* FileSrc)
{
	tools_log(); printf("count lines in %s: ",FileSrc);	

    FILE *fileR = fopen(FileSrc,"r");
    int lines = -1;

    if (NULL!=fileR)
    {
        lines = 0;
        char *line = (char*)malloc(21);
        size_t n=20;
        ssize_t len;
        
        while ( (len=getline(&line, &n, fileR))>0 )
            ++lines;

        free(line);
        fclose(fileR);
    }
    
    printf("%d \n\n",lines);
}

void readAndWriteTextFile(string fileName, string fileOut)
{
	tools_log(); cout << "copy C++-style, version 1" << endl;
    	
    string line;
    int no=1;
    
    // one way to read
    ifstream filer(fileName);
    if (filer.is_open()) {
        while (getline(filer,line)) // or: while (! filer.eof() )
            cout << "\tno " << (no++) << ": '" << line << "'\n";
        filer.close();
    } else {
        tools_log(); cout << "could not read file"; 
    }
    
    // one way to write
    ofstream filew(fileOut);
    if (filew) {
        filew << "ok, here it is: the first line" << endl;
        filew.close();
    }

}

int main()
{   
    string fileName("./file.txt");
    const char* pFileName = fileName.c_str();
    
    // C-Style
	tools_log(); printf("copy files \n");	
    copyFileCharByChar(pFileName,"./fileCopy.txt");
    
	tools_log(); printf("count words \n");	
    countWords(pFileName);
    
	tools_log(); printf("count lines \n");	
    countLines(pFileName);
    
    // C++-style
    readAndWriteTextFile(fileName, "./fileOneLine.txt");

    return EXIT_SUCCESS;
}

