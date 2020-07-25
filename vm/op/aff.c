#include "corewar.h"

void    op_aff(t_vm *vm, t_cursor *cursor)
{
    int reg;
    int val;

    cursor->step += OP_CODE_LEN;
    reg = get_byte(cursor->pos + cursor->step, vm);
    val = cursor->reg[reg - 1];
    cursor->step += REG_LEN;
    if (vm->display_aff)
		  ft_printf("Aff: %c\n", (char)val);
}