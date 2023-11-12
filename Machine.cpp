#include <fstream>
#include "Machine.h"
#include "Memory.h"
#include "Operation.h"



void Machine::fileHandler(string fileName) {

    // memory ram;
    // memory reg('R');

    fileName.append(".txt");
    ifstream file(fileName);

    string line;
    int lineNumber = 1;
    while (getline(file, line)) {

    

    int counter = 1;
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



    int cell2 = hexToDecimal(v[2]);


    // write_command(order number, instruction code, Register 1, Register 2);
    ram->write_command(counter, hexToDecimal(v[0]), hexToDecimal(v[1]), hexToDecimal(v[2]));
    counter += 2;

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
void Machine::excute_operation()
{
    for(int i = 1; i > ram->size;i+=2)
    {
        crrunt->set_Operation(ram->get_command(i));
        if(crrunt->do_Operation())
        {
            delete ram;
            delete reg;
            delete crrunt;
            exit(EXIT_SUCCESS);
        }
        
    }
}