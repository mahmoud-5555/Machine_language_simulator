#ifndef OPERATION_H
#define OPERATION_H

#include "main.h"

using namespace std;
/**
 *  Operation is a data type to handel the Operation in the type know how to deal with the Operation
*/

class Operation
{
	private:
		Memory *ram = NULL;
		Memory *reg = NULL; 
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
		Operation(int in_put, Memory *Ram,Memory *Reg);
		Operation(Memory *Ram,Memory *Reg);
		void set_Operation(int in_put);
		int do_Operation();

};

#endif 