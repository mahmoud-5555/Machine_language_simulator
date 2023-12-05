#include <iostream>
#include "main.h"
using namespace std;

int Memory::status = 0;
int oprateion_iterator;
int main() {

    
    string path;
    ifstream file;

    cout << "Enter file1 path: ";
    cin >> path; 

    path.append(".txt");
    file.open(path);

    Machine *m1 = new Machine();
    m1->fileHandler(file);
    m1->excute_operation();
    delete m1;

}