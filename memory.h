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
class memory{
	private:
		int size;
		short int  *memory_calls;
		vector <string> memory_errors;
		static unsigned long long status;

	public:
		memory();
		memory(char type_of_memory);
		short int read_memory(short int call_address);
		bool write_memory(short int call_address, short int value);
		void get_command(short int address);
		void write_command(short int address, char order, char R,short int ST);
		~memory();
};
#endif