#include"main.h"
/**
 * memory - construcor have 2 type of over_loading
 * first: no args the size will be 256(defult)
 * sacend: with spcfie the size 
 */
Memory::Memory()
{
	size = 256;
	memory_cells = new unsigned char [size];
}

Memory:: Memory(char type_of_memory)
{
	if(type_of_memory == 'R')
	{
		size = 16;
		memory_cells = new unsigned char[size];
	}
	else if(type_of_memory == 'M')
	{
		size = 256;
		memory_cells = new unsigned char [size];
	}
}
/// @brief function use to rad the vlaue in the memory acsses to even selas to got the true value
/// @param call_address  the statrt raad point "red two byte two seals"
/// @return the  value in the memory 
short Memory::read_memory(short call_address)
{
	status++;
	//check if address in the boundary of the memory
	if(call_address >= 0 && call_address < this ->size  - 1)
	{
		return ((short)memory_cells[call_address] *16 + (short)memory_cells[call_address + 1]);
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

bool Memory::write_memory(short call_address, short value)
{
	status++;
	if(call_address >= 0 && call_address < this ->size - 1)
	{
		memory_cells[call_address] = value / 16;
		memory_cells[call_address + 1] = value % 16;
	}
	else
	{
		string error_status = to_string(status);
		if(size == 256)
				memory_errors.push_back("$ RAM : weite memory error status: " + error_status);
		else			
				memory_errors.push_back("$ Rojester : write memory error status: " + error_status);
		return (0);
	}
	return(true);

}

/// @brief delete_value re_assain the value by zero
/// @param address start from the addres_value and the next one
void Memory::delete_value(short address)
{
	if(address >= 0 &&address < size - 1)
	{
		memory_cells[address] = 0;
		memory_cells[address + 1] = 0;
	}
	
}


/**
 * ~Memory - destructer to free the located memory "in the heap" 
*/
Memory::~Memory()
{
	delete memory_cells;
}

/// @brief write_command - function use to store the instructar of commands
/// @param address the start add
/// @param order thoe order value
/// @param R the R_value in the memory
/// @param ST the ST_value
void Memory::write_command(short address, char order, char R,short ST)
{
	if (address < size - 3)
	{
		memory_cells[address] = (unsigned char) order;
		memory_cells[address + 1] = (unsigned char) R;
		memory_cells[address + 2] = (unsigned char)(ST >> 4);
		memory_cells[address + 3] = (unsigned char)(ST % 16);
	}
}
/// @brief get_command function that raad an command "the command stord in 4 byte 4 selaes"
/// @param address the start address
/// @return 
unsigned short Memory::get_command(short address)
{
	if (address < size - 3)
	{
		short the_command = memory_cells[address] *(16*16*16);
		the_command += (short)memory_cells[address + 1]* (short)(16 *16);
		the_command += (short) memory_cells[address + 2]*(short)(16);
		the_command += (short) memory_cells[address + 3];
		return ((short) memory_cells[address] + (short) memory_cells[address + 1]);
	}
}

void Memory ::clear_memory()
{
	for(short i = 0; i < size;i++)
		memory_cells[i] = 0;
}

