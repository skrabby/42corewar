#include "corewar.h"

void    op_st(t_vm *vm, t_cursor *cursor)
{
    int reg;
    int l_reg;
    int val;

    cursor->step += OP_CODE_LEN + ARGS_CODE_LEN;
    reg = get_byte(cursor->pos + cursor->step, vm);
    val = cursor->reg[reg - 1];
    cursor->step += REG_LEN;
    if (cursor->args_types[1] == T_REG)
    {
        l_reg = get_byte(cursor->pos + cursor->step, vm);
        cursor->reg[l_reg - 1] = val;
        cursor->step += REG_LEN;
    }
    else
    {
        l_reg = bytecode_to_int_op(vm->arena,
							cursor->pos + cursor->step, IND_SIZE);
        int_to_bytecode(vm->arena, cursor->pos + (l_reg % IDX_MOD),
							val, DIR_SIZE);
        cursor->step += IND_SIZE;
    }
    vm->loger_on == 1 ? ft_printf("P %4d | st r%d %d\n", cursor->id, reg, l_reg) : 0;
}