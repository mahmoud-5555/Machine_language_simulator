#ifndef MEMORY_H
#define MEMORY_H

#include<iostream>
#include<vector>
#include<string>
using namespace std;
class memory{
	private:
		int size;
		short int *memory_calls;
		vector <string> memory_errors;
		static unsigned long long status;

	public:
		memory();
		memory(char type);
		short int read_memory(short int call_address);
		bool write_memory(short int call_address, short int value);
		~memory();
};
#endif