#ifndef MAIN_H
#define MAIN_H

#include <fstream>
#include <stdexcept>
#include <string>
#include <iostream>
#include <vector> 
#include <iostream>
using namespace std ;




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
class Memory {
private:
	unsigned char* memory_cells;
	std::vector <std::string> memory_errors;


public:
	short size;
	static int status;
	Memory();
	Memory(char type_of_memory);
	short read_memory(short  call_address);
	void delete_value(short address); // delete value in address 
	bool write_memory(short  call_address, short value);
	unsigned short get_command(short address);//the order
	void write_command(short  address, char order, char R, short ST);
	void clear_memory();
	~Memory();
};
//_________________________Operation___________________________________
class Operation
{
private:
	Memory* ram = NULL;
	Memory* reg = NULL;
	unsigned char order;
	unsigned char R_Value;
	unsigned char S_Value;
	unsigned char T_Value;

	void Register_load_memory();//load from memory to Register
	void Register_load_value();//load the value to Register
	void store_memory();//store what in the Register in the "RAM_Call"
	void move_to_another_Register();// move the value in Register "S_Value" to T_value
	void add_two_s_complement();// add 'S'and 'T' load in 'R'
	int exit_op();
	void jump();
public:
	Operation();
	Operation(short in_put, Memory* Ram, Memory* Reg);
	Operation(Memory* Ram, Memory* Reg);
	void set_Operation(short in_put);
	int do_Operation();


};
//____________________________Machin________________________________
class Machine
{
	Memory* ram = new Memory;
	Memory* reg = new Memory('R');
	Operation* crrunt = new Operation(ram, reg);
public:
	void fileHandler(std::ifstream& file);
	int hexToDecimal(std::string hexNumer);
	void excute_operation();
	void print_the_Screan();
};

extern int oprateion_iterator;

#endif