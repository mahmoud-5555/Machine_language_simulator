#include"memory.h"
/**
 * memory - construcor have 2 type of over_loading
 * first: no args the size will be 256(defult)
 * sacend: with spcfie the size 
 */
memory :: memory()
{
	size = 256;
	memory_calls = new short int[size];
}
memory:: memory(char type)
{
	if(type == 'R')
	{
		size = 16;
		memory_calls = new short int[size];
	}
	else if(type == 'M')
	{
		size = 256;
		memory_calls = new short int[size];
	}
}
short int memory::read_memory(short int call_address)
{
	status++;
	//check if address in the boundary of the memory
	if(call_address > 0 && call_address < this ->size)
	{
		return (memory_calls[call_address]);
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
bool memory::write_memory(short int call_address, short int value)
{
	status++;
	if(call_address > 0 && call_address < this ->size)
	{
		memory_calls[call_address] = value;
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
/**
 * ~memory - destructer to free the located memory "in the heap" 
*/
memory:: ~memory()
{
	delete memory_calls;
}


