#ifndef MACHINE_H
#define MACHINE_H
#include <istream>
#include <fstream>
#include <string>
#include "memory.h"
#include "operation.h"
class Machine
{
	memory memory_ram;
	memory _reg('R');


    public:
    void fileHandler(string fileName);
    int hexToDecimal(string hexNumer);
};
#endif