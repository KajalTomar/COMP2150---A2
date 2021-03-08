#include "FileReader.h"
#include <assert.h>
#include "Process.h"
#include <iostream>
using namespace std;

FileReader::FileReader() { }

FileReader::FileReader(char * fileName) {
    inFile.open(fileName);
    assert(inFile);
    if (!inFile.is_open()) {
        cout << "An error occured while opening the files" << endl;
    }
}

int FileReader::getQuantumNumber() {
    int quantumNumber = 0;

    if(inFile.is_open()) {
        inFile >> quantumNumber;
        inFile.ignore();
    }

    return quantumNumber;

}

bool FileReader::isEmpty() { return inFile.eof();}

string FileReader::getLine(){
    string line;
    if(inFile.is_open()) {
        getline(inFile, line);
    }

    return line;
}

void FileReader::closeFile() {
    inFile.close();
    assert(!inFile.is_open());
}
