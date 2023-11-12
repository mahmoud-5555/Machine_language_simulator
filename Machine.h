#ifndef MACHINE_H
#define MACHINE_H
#include <istream>
#include <fstream>
#include <string>
#include "memory.h"
#include "operation.h"
class Machine 
{   
    Memory* ram = new Memory;
    Memory* reg = new Memory('R');
    public:
    void fileHandler(string fileName);
    int hexToDecimal(string hexNumer);
<<<<<<< HEAD
    memory ran('R');
=======
>>>>>>> refs/remotes/origin/main
};
#endif