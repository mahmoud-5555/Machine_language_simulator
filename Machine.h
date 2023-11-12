#ifndef MACHINE_H
#define MACHINE_H
#include <istream>
#include <fstream>
#include <string>
#include "memory.h"
#include "operation.h"
class Machine : public memory
{
	memory memory_ram;
	memory reg('R');


    public:
    void fileHandler(string fileName);
    int hexToDecimal(string hexNumer);
    memory ran('r');
};
#endif