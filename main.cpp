#include <iostream>
#include "main.h"

using namespace std;

int main() {

    string fileName;
    cout << "Enter File name: ";
    cin >> fileName;

    Machine *m1 = new Machine();
    m1->fileHandler(fileName);
    m1->excute_operation();

}