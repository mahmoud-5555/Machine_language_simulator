#ifndef MACHINE_H
#define MACHINE_H
#include <istream>
#include <fstream>
#include <string>
#include "memory.h"
#include "operation.h"
class machine
{
	memory memory_ram;
	memory _reg('R');


    public:
    friend void operator>>(istream& is, string fileName);



};
#endif