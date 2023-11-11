#include <fstream>
#include "Machine.h"
#include "memory.h"
#include "operation.h"



void Machine::fileHandler(string fileName) {

    fileName.append(".txt");
    ifstream file(fileName);

    string line;
    int lineNumber = 1;
    while (getline(file, line)) {


    vector<string> v;

    char separator = ' ';

    // store every string chars in copy string
    string copy;
    
    for (int i = 0; i < line.size(); i++) {
        // if char in str is " " then push back to vector as one string and clear it
        if (line[i] == separator) {
            v.push_back(copy);
            copy.clear();
        }
        // other wise will keep add char to string copy
         else {
            copy += line[i];
        }
    }

    // Push the last word into the vector (it may not end with a space)
    v.push_back(copy);


    int orderNumer = hexToDecimal(v[0]);
    int cell1 = hexToDecimal(v[1]);
    int cell2 = hexToDecimal(v[2]);





    }  


}


int Machine::hexToDecimal(string hexNumber) {



  // Check if the string starts with "0x" and remove it
    if (hexNumber.substr(0, 2) == "0x") {
        hexNumber = hexNumber.substr(2);
    }

    // Convert hex string to integer
    int decimalNumber = std::stoi(hexNumber, nullptr, 16);
    return decimalNumber;


}