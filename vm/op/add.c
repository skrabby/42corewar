#include "corewar.h"

void    op_add(t_vm *vm, t_cursor *cursor)
{
    int reg1;
    int reg2;
    int reg3;
    int value;

    cursor->step += (OP_CODE_LEN + ARGS_CODE_LEN);
    reg1 = get_byte(cursor->pos + cursor->step, vm);
    cursor->step += REG_LEN;
    reg2 = get_byte(cursor->pos + cursor->step, vm);
    cursor->step += REG_LEN;
    value = cursor->reg[reg1] + cursor->reg[reg2];
    if (value == 0) 
        cursor->carry = 1;
    else
        cursor->carry = 0;
    reg3 = get_byte(cursor->pos + cursor->step, vm);
    cursor->reg[reg3 - 1] = value;
    cursor->step += REG_LEN;
}