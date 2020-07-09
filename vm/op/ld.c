#include "corewar.h"


void    op_ld(t_vm *vm, t_cursor *cursor)
{
    int value;
    int reg;

    cursor->step += (OP_CODE_LEN + ARGS_CODE_LEN);
    value = get_arg();
    value == 0 ? carry = 1 : carry = 0;
    reg = get_reg()
    save_to_reg();
} 