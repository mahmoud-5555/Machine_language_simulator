#include "operation.h"

Operation::Operation()
{
    order = 0;
    R_Value = 0;
    S_Value = 0;
    T_Value = 0;
}


void Operation::Register_load_memory(unsigned char R_value, short int  ST_value, Memory &ram,Memory &reg) {
    reg.write_memory(R_value, ram.read_memory(ST_value)); 
}

void Operation::Register_load_value(unsigned char R_value, short int  ST_value,Memory &reg) {
    reg.write_memory(R_Value, ST_value); 
}

void Operation::move_to_another_Register(unsigned char R_Value, short int  ST_value, Memory &reg) {
    reg.write_memory(ST_value, reg.read_memory(R_Value));
    reg.delete_value(R_Value);

}


void Operation::store_memory(unsigned char R_Value, short int  ST_value, Memory &ram,Memory &reg) {
    if (ST_value == 0) {
        cout << R_Value;
        return;
    }
    ram.write_memory(ST_value,reg.read_memory(R_Value));
}

//bool write_memory(short int call_address, short int value);
// short int read_memory(short int call_address);
// void delete_value(short int address); // delete value in address 
// bool write_memory(short int call_address, short int value);
// int get_command(short int address);//the order
// void write_command(short int address, char order, char R,short int ST);

void Operation::add_two_s_complement(unsigned char R_Value, unsigned char S_Value ,unsigned char T_value, Memory &reg) {
    unsigned char num1 = reg.read_memory(S_Value);
    unsigned char num2 = reg.read_memory(T_value);
    reg.write_memory(R_Value, num1 + num2);
}


int Operation::exit_op() {
    return 1;
};

 
//jump to the command
/*
void jump(unsigned char R_value, short int ST_value,short int the_itoretor_of_operarion,memory &reg)
{
    
}
'''
*/
Operation::Operation(int in_put)
{
    this->order = (in_put >> 12) & 0x000f;
    this->R_Value = ((in_put << 4)>>12) & 0x000f;
    this->S_Value = ((in_put << 8)>>12) & 0x000f;
    this->T_Value = ((in_put << 12)>>12) & 0x000f;
}