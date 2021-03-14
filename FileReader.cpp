//--------------------------------------------
// CLASS: FileReader.cpp
//
// Author: Kajal Tomar, 7793306
//
// REMARKS: provides methods to read a file.
//--------------------------------------------
#include "FileReader.h"
#include <assert.h>
#include "Process.h"
#include <iostream>
using namespace std;

//------------------------------------------------------
// FileReader
//
// PURPOSE: the constructor for a FileReader object.
//      opens a file.
// PARAMETERS: pointer to file name
//------------------------------------------------------
FileReader::FileReader(char * fileName) {
    inFile.open(fileName); // open file

    assert(inFile);

    if (!inFile.is_open()) {
        cout << "An error occured while opening the files" << endl;
    }
}

//------------------------------------------------------
// getQuantumNumber
//
// PURPOSE: returns the quantum number (first line) from
// file.
// RETURNS: int (quantum number)
//------------------------------------------------------
int FileReader::getQuantumNumber() {
    int quantumNumber = 0;

    if(inFile.is_open()) {
        // make sure the file is open

        // read in the quantum number from the first line
        inFile >> quantumNumber;
        //ignore the rest of the line
        inFile.ignore();
    }

    return quantumNumber;
}

//------------------------------------------------------
// isEmpty
//
// PURPOSE: to check is the file is empty
// RETURNS: true if the file is empty, false otherwise
//------------------------------------------------------
bool FileReader::isEmpty() { return inFile.eof();}

//------------------------------------------------------
// getLine
//
// PURPOSE: gets the next line in the file if there is one
// RETURNS: a string line
//------------------------------------------------------
string FileReader::getLine(){
    string line;
    if(inFile.is_open()) {
        getline(inFile, line);
    }

    return line;
}

//------------------------------------------------------
// closeFile
//
// PURPOSE: closes the file
//------------------------------------------------------
void FileReader::closeFile() {
    inFile.close();
    assert(!inFile.is_open());
}
