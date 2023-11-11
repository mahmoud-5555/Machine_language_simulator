#ifndef MACHINE_H
#define MACHINE_H

#include "memory.h"
#include "operation.h"
class machine
{
	memory memory_ram;
	memory _reg('R');


    public:
    istream & operator >> (istream &in,  fileName &c);



}
#endif