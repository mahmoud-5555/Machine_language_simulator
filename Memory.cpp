#include"memory.h"
/**
 * memory - construcor have 2 type of over_loading
 * first: no args the size will be 256(defult)
 * sacend: with spcfie the size 
 */
Memory::Memory()
{
	size = 256;
	memory_cells = new short int[size];
}

Memory:: Memory(char type_of_memory)
{
	if(type_of_memory == 'R')
	{
		size = 16;
		memory_cells = new short int[size];
	}
	else if(type_of_memory == 'M')
	{
		size = 256;
		memory_cells = new short int[size];
	}
}

short int Memory::read_memory(short int call_address)
{
	status++;
	//check if address in the boundary of the memory
	if(call_address > 0 && call_address < this ->size)
	{
		return (memory_cells[call_address]);
	}
	else
		{
			string error_status = to_string(status);
			if(size == 256)
				memory_errors.push_back("$ RAM : reading memory error status: " + error_status);
			else
				memory_errors.push_back("$ Rojester : reading memory error status: " + error_status);
		}
}
bool Memory::write_memory(short int call_address, short int value)
{
	status++;
	if(call_address > 0 && call_address < this ->size)
	{
		memory_cells[call_address] = value;
	}
	else
	{
		string error_status = to_string(status);
		if(size == 256)
				memory_errors.push_back("$ RAM : weite memory error status: " + error_status);
		else			
				memory_errors.push_back("$ Rojester : write memory error status: " + error_status);
	}

}


void Memory::delete_value(short int address) {
	memory_cells[address] = 0;
}



/**
 * ~memory - destructer to free the located memory "in the heap" 
*/
Memory::~Memory()
{
	delete memory_cells;
}
void Memory::write_command(short int address, char order, char R,short int ST)
{
	short int f_half = order * 16 + R;
	memory_cells[address] = f_half;
	memory_cells[address + 1] = ST;
}


