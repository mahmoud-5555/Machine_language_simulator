#include <istream>
#include "Machine.h"
#include "memory.h"
#include "operation.h"


void operator>>(istream& is, string fileName) {

    fileName.append(".txt");
    ifstream file(fileName);

    string line;
    int lineNumber = 1;
    while (getline(file, line)) {


    vector<string> strs;
    string str;

    char separator = ' ';

    // store every string chars in copy string
    string copy;
    
    for (int i = 0; i < line.size(); i++) {
        // if char in str is " " then push back to vector as one string and clear it
        if (str[i] == separator) {
            strs.push_back(copy);
            copy.clear();
        }
        // other wise will keep add char to string copy
         else {
            copy += str[i];
        }
    }

    // Push the last word into the vector (it may not end with a space)
    strs.push_back(copy);

    // 

    }

    // Your code to read from the file using 'file' stream goes here
}