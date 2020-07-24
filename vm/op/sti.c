#include "corewar.h"

void    op_sti(t_vm *vm, t_cursor *cursor)
{
    int reg1;
    int val2;
    int val3;
    int val;

    cursor->step = OP_CODE_LEN + ARGS_CODE_LEN;
    reg1 = get_byte(cursor->pos + cursor->step, vm);
    val = cursor->reg[reg1 - 1];
    cursor->step += REG_LEN;
    val2 = get_arg(vm, cursor, 2, 1);
    val3 = get_arg(vm, cursor, 3, 1);
    int32_to_bytecode(vm->arena,
			(cursor->pos + ((val2 + val3) % IDX_MOD)), val, DIR_SIZE);
}