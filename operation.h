#ifndef OPERATION_H
#define OPERATION_H

#include "memory"
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
		unsigned char T_value;

		char Register_load_memory(unsigned char R_Value, short int  ST_value);//load from memory to Register
		char Register_load_value(unsigned char R_Value, short int  ST_value);//load the value to Register
		char store_memory(unsigned char R_Value, short int  ST_value);//store what in the Register in the "RAM_Call"
		char move_to_anter_Register(unsigned char S_Value, unsigned char T_value);// move the value in Register "S_Value" to T_value
		char add_two_s_complement(unsigned char R_Value, unsigned char S_Value ,unsigned char T_value);// add 'S'and 'T' load in 'R'
		char add_floating_point(unsigned char R_Value, unsigned char S_Value ,unsigned char T_value);// add 'S'and 'T' load in 'R'
		char jumb();
		char exit_op();
	public:
		Operation();
		Operation(short int in_put);
		char do_Operation();

};

#endif