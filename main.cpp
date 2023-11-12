#include <iostream>
#include "Machine.h"

using namespace std;

int main() {


    string fileName;
    cout << "Enter File name: ";
    cin >> fileName;

    Machine *m1 = new Machine();
    m1->fileHandler(fileName);

}