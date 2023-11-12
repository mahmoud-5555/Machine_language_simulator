#include "operation.h"

Operation::Operation()
{
    order = 0;
    R_Value = 0;
    S_Value = 0;
    T_Value = 0;
}


void Operation::Register_load_memory() {
    short int ST_value = (short int) S_Value* 16 + (short int) T_Value;
    reg->write_memory(R_Value, ram->read_memory(ST_value)); 
}

void Operation::Register_load_value() {
    short int ST_value = (short int) S_Value* 16 + (short int) T_Value;
    reg->write_memory(R_Value, ST_value); 
}

void Operation::move_to_another_Register() {
    short int ST_value = (short int) S_Value* 16 + (short int) T_Value;
    reg->write_memory(ST_value, reg->read_memory(R_Value));
    reg->delete_value(R_Value);

}


void Operation::store_memory() {
    short int ST_value = (short int) S_Value* 16 + (short int) T_Value;
    if (ST_value == 0) {
        cout << R_Value;
        return;
    }
    ram->write_memory(ST_value,reg->read_memory(R_Value));
}

//bool write_memory(short int call_address, short int value);
// short int read_memory(short int call_address);
// void delete_value(short int address); // delete value in address 
// bool write_memory(short int call_address, short int value);
// int get_command(short int address);//the order
// void write_command(short int address, char order, char R,short int ST);

void Operation::add_two_s_complement() {
    unsigned char num1 = reg->read_memory(S_Value);
    unsigned char num2 = reg->read_memory(T_Value);
    reg->write_memory(R_Value, num1 + num2);
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
Operation::Operation(int in_put,Memory *Ram,Memory *Reg)
{
    this->ram = Ram;
    this->reg = Reg;

    this->order = (in_put >> 12) & 0x000f;
    this->R_Value = ((in_put << 4)>>12) & 0x000f;
    this->S_Value = ((in_put << 8)>>12) & 0x000f;
    this->T_Value = ((in_put << 12)>>12) & 0x000f;
}

int Operation:: do_Operation()
{
    switch (order)
    {
    case 1:
        Register_load_memory();
        break;
    case 2:
        /* code */
        break;
    case 3:
        /* code */
        break;
    case 4:
        /* code */
        break;
    case 5:
        /* code */
        break;
    case 6:
        /* code */
        break;
    case 11:
        /* code */
        break;
    case 12:
        /* code */
        break;
    case 0:
        /* code */
        break;
    
    default:
        break;
    }
}