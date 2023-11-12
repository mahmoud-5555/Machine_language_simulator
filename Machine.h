#ifndef MACHINE_H
#define MACHINE_H
#include <istream>
#include <fstream>
#include <string>
#include "memory.h"
#include "operation.h"
class Machine 
{   
    Memory *ram = new Memory;
    Memory *reg = new Memory('R');
    Operation *crrunt = new Operation(ram,reg);
    public:
    void fileHandler(string fileName);
    int hexToDecimal(string hexNumer);
    void excute_operation();
};
#endif