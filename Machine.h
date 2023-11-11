#ifndef MACHINE_H
#define MACHINE_H
#include <istream>
#include "memory.h"
#include "operation.h"
class machine
{
	memory memory_ram;
	memory _reg('R');


    public:
    friend istream & operator >> (istream &in, string fileName);



};
#endif