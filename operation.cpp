#include "operation.h"


Operation::Operation()
{
    order = 0;
    R_Value = 0;
    S_Value = 0;
    T_value = 0;
    ST_value = 0;
}


// void Operation::Register_load_memory(unsigned char R_Value, short int  ST_value, memory &ram,memory &reg) {
//     reg.load_memory(R_Value, ram.read_memory(ST_value)); 
// }