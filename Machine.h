#ifndef MACHINE_H
#define MACHINE_H
#include <istream>
#include <fstream>
#include <string>
#include "memory.h"
#include "operation.h"
class Machine : public memory
{
    
    public:
    void fileHandler(string fileName);
    int hexToDecimal(string hexNumer);
    memory ran('R');
};
#endif