#include "corewar.h"

void    op_st(t_vm *vm, t_cursor *cursor)
{
    int reg;
    int l_reg;
    int val;

    cursor->step += OP_CODE_LEN + ARGS_CODE_LEN;
    reg = get_byte(cursor->pc + cursor->step, vm);
    val = cursor->reg[reg - 1];
    cursor->step += REG_LEN;
    if (cursor->args_types[1] = T_REG)
    {
        l_reg = get_byte(cursor->pc + cursor->step, vm);
        cursor->reg[l_reg - 1] = val;
        cursor->step += REG_LEN;
    }
    else
    {
        l_reg = bytecode_to_int32(vm->arena,
							cursor->pos + cursor->step, IND_SIZE);
        int32_to_bytecode(vm->arena, cursor->pos + (l_reg % IDX_MOD),
							val, DIR_SIZE);
        cursor->step += IND_SIZE;
    }
}