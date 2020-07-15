#include "corewar.h"


void    op_ldi(t_vm *vm, t_cursor *cursor)
{
    int val1;
    int val2;
    int reg;

    cursor->step += (OP_CODE_LEN + ARGS_CODE_LEN);
    val1 = get_arg(vm, cursor, 1, true);
    val2 = get_arg(vm, cursor, 2, true);
    reg = get_byte(cursor->pc + cursor->step, vm);
    cursor->reg[reg - 1] = bytecode_to_int32(vm->arena, 
                            cursor->pos + (val1 + val2) % IDX_MOD, DIR_SIZE);
    cursor->step += REG_LEN;
}