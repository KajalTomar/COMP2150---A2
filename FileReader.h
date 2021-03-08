//--------------------------------------------
// CLASS: FileReader.h
//
// Author: Kajal Tomar, 7793306
//
// REMARKS: class definitions for the FileReader.cpp
// class.
//
//--------------------------------------------
#include <fstream>
#include<string>

using namespace std;

class FileReader {
private:
    fstream inFile;
public:
    FileReader();
    FileReader(char * fileName);

    string getLine();
    int getQuantumNumber();
    bool isEmpty();
    void closeFile();

};// Filereader