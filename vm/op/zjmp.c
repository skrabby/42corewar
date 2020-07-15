# include "corewar.h"

void				op_zjmp(t_vm *vm, t_cursor *cursor)
{
    int val;

    cursor->step += OP_CODE_LEN;
    val1 = get_arg(vm, cursor, 1, true);
    if (cursor->carry == 1)
        cursor->pos = find_addr(cursor->pos + (val1 % IDX_MOD));
        cursor->step = 0;
    else
        return ;
}