#include "Operation.h"

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
void Operation::jump()
{
    short int ST_value = (short int) S_Value* 16 + (short int) T_Value;
    if(reg->read_memory(0) == reg->read_memory(R_Value))
        oprateion_iterator  = ST_value;
}

Operation::Operation(int in_put,Memory *Ram,Memory *Reg)
{
    this->ram = Ram;
    this->reg = Reg;

    this->order = (in_put >> 12) & 0x000f;
    this->R_Value = ((in_put << 4)>>12) & 0x000f;
    this->S_Value = ((in_put << 8)>>12) & 0x000f;
    this->T_Value = ((in_put << 12)>>12) & 0x000f;
}

void Operation::set_Operation(int in_put)
{
    this->order = (in_put >> 12) & 0x000f;
    this->R_Value = ((in_put << 4)>>12) & 0x000f;
    this->S_Value = ((in_put << 8)>>12) & 0x000f;
    this->T_Value = ((in_put << 12)>>12) & 0x000f;
}
Operation::Operation(Memory *Ram,Memory *Reg)
{
    this->ram = Ram;
    this->reg = Reg;
}

int Operation:: do_Operation()
{
    switch (order)
    {
    case 1:
        Register_load_memory();
        break;
    case 2:
        Register_load_value();
        break;
    case 3:
        store_memory();
        break;
    case 4:
        move_to_another_Register();
        break;
    case 5:
        add_two_s_complement();
        break;
    case 11:
        jump();
        break;
    case 12:
        return(1);// exit from the program
        break;
    }
    return(0);
}