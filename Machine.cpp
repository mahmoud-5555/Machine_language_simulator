#include"main.h"

void Machine::fileHandler(ifstream& file) {

    string line;
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

    ram->write_command(counter, hexToDecimal(v[0]), hexToDecimal(v[1]), hexToDecimal(v[2]));
    counter += 2;

    }  
    file.close();

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
void Machine :: print_the_Screan()
{
    for (short i = 0; i < 256; i += 32)
    {
        //cout << hex << reg->read_memory(i/16) << " | ";
        printf("%x | ",reg->read_memory((short)i/16));
        for(short j = i; j < (i + 32); j += 2)
        {
            if(j < i + 30)
                cout << hex << ram->read_memory(j) << ' ';    
            else
                cout << hex << ram->read_memory(j) << endl;
        }
    }
    cout<<"___________________________________\n";
}

void Machine::excute_operation()
{
    //system ("CLS");
    //print_the_Screan();
    for(oprateion_iterator = 0; oprateion_iterator < ram->size; oprateion_iterator+=2)
    {
        //system ("CLS");
        crrunt->set_Operation(ram->get_command(oprateion_iterator));
        print_the_Screan();
        //Sleep(1000);
        if(crrunt->do_Operation())
        {
            delete ram;
            delete reg;
            delete crrunt;
            exit(EXIT_SUCCESS);
        }
        
         
        

    }
}