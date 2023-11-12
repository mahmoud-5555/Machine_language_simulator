#ifndef OPERATION_H
#define OPERATION_H

#include <stdexcept>
#include "Memory.h"

using namespace std;
/**
 *  Operation is a data type to handel the Operation in the type know how to deal with the Operation
*/

class Operation
{
	private:
		unsigned char order;
		unsigned char R_Value;
		unsigned char S_Value;
		unsigned char T_Value;

		void Register_load_memory(unsigned char R_Value, short int  ST_value, Memory &ram,Memory &reg);//load from memory to Register
		void Register_load_value(unsigned char R_Value, short int  ST_value, Memory &reg);//load the value to Register
		void store_memory(unsigned char R_Value, short int  ST_value, Memory &ram,Memory &reg);//store what in the Register in the "RAM_Call"
		void move_to_another_Register(unsigned char R_Value, short int  ST_value, Memory &reg);// move the value in Register "S_Value" to T_value
		void add_two_s_complement(unsigned char R_Value, unsigned char S_Value ,unsigned char T_value, Memory &ram);// add 'S'and 'T' load in 'R'
		int exit_op();
		void jump(unsigned char R_value, short int ST_value);
		void exit_op();
	public:
		Operation();
		Operation(int in_put);
		int do_Operation();

};

#endif 