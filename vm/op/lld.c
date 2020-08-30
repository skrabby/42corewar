#include "corewar.h"

void    op_lld(t_vm *vm, t_cursor *cursor)
{
	int val;
	int reg;

	cursor->step += OP_CODE_LEN + ARGS_CODE_LEN;
	val = get_arg(vm, cursor, 1, 1);
	if (val == 0)
        cursor->carry = 1;
    else
        cursor->carry = 0;
	reg = get_byte(cursor->pos + cursor->step, vm);
	cursor->reg[reg - 1] = val;
	cursor->step += REG_LEN;
    vm->loger_on == 1 ? ft_printf("P %4d | lld %d r%d\n", cursor->id, val, reg) : 0;
}
