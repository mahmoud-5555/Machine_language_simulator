#include "Operation.h"


Operation::Operation()
{
    order = 0;
    R_Value = 0;
    S_Value = 0;
    T_value = 0;
}


void Operation::Register_load_memory(unsigned char R_Value, short int  ST_value, Memory &ram,memory &reg) {
    reg.write_memory(R_Value, ram.read_memory(ST_value)); 
}

void Operation::Register_load_value(unsigned char R_Value, short int  ST_value, Memory &ram,memory &reg) {
    reg.write_memory(R_Value, ST_value); 
}

void Operation::move_to_another_Register(unsigned char R_Value, short int  ST_value, Memory &reg) {
    reg.write_memory(ST_value, ram.read_memory(R_Value));
    ram.delete_value(R_Value);
}

//bool write_memory(short int call_address, short int value);
// short int read_memory(short int call_address);
// void delete_value(short int address); // delete value in address 
// bool write_memory(short int call_address, short int value);
// int get_command(short int address);//the order
// void write_command(short int address, char order, char R,short int ST);

void Operation::add_two_s_complement(unsigned char R_value, unsigned char S_value ,unsigned char T_value, memory &reg) {

    unsigned char num1 = reg.read_memory(S_value);
    unsigned char num2 = reg.read_memory(T_value);
    reg.write_memory(R_Value, num1 + num2);
}
//jump to the command
'''
void jump(unsigned char R_value, short int ST_value,short int the_itoretor_of_operarion,memory &reg)
{
    
}
'''
Operation::Operation(int in_put)
{
    this->order = (in_put >> 12) & 0x000f;
    this->R_Value = ((in_put << 4)>>12) & 0x000f;
    this->S_Value = ((in_put << 8)>>12) & 0x000f;
    this->T_Value = ((in_put << 12)>>12) & 0x000f;
}