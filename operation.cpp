#include "operation.h"


Operation::Operation()
{
    order = 0;
    R_Value = 0;
    S_Value = 0;
    T_value = 0;
}


void Operation::Register_load_memory(unsigned char R_Value, short int  ST_value, memory &ram,memory &reg) {
    reg.write_memory(R_Value, ram.read_memory(ST_value)); 
}

void Operation::Register_load_value(unsigned char R_Value, short int  ST_value, memory &ram,memory &reg) {
    reg.write_memory(R_Value, ram.read_memory(ST_value)); 
}

void Operation::add_two_s_complement(unsigned char R_Value, unsigned char S_Value ,unsigned char T_value, memory &ram) {

    unsigned char num1 = ram.read_memory(R_Value);
    unsigned char num2 = ram.read_memory(S_Value);
    

}