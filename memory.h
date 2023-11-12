#ifndef MEMORY_H
#define MEMORY_H

#include<iostream>
#include<vector>
#include<string>

using namespace std;
/**
 * class memory - class "data type to make the simulator of the memory"
 * @size:the size of the memory how meny call that memory had
 * @memory_error:tracker to memory error to make an reprot of the memory behavir
 * @status: is an id of the memory opration to help tracking
 * memory opration in the report
 * 
 * the memory has function "read_memory", "write memory" the class well be response
 * of memory mangment
*/
class Memory{
	private:
		int size;
		short int  *memory_cells;
		vector <string> memory_errors;
		static unsigned long long status;

	public:
		Memory();
		Memory(char type_of_memory);
		short int read_memory(short int call_address);
		void delete_value(short int address); // delete value in address 
		bool write_memory(short int call_address, short int value);
		int get_command(short int address);//the order
		void write_command(short int address, char order, char R,short int ST);
		~Memory();
};
#endif