#include "corewar.h"

void    op_lfork(t_vm *vm, t_cursor *cursor)
{
	int         val;
	t_cursor	*new_cur;

	cursor->step += OP_CODE_LEN;
	val = get_arg(vm, cursor, 1, 1);
	new_cur = dupl_cur(cursor, val);
	add_cur(&(vm->cursors), new_cur);
	vm->cursors_num++;
    vm->loger_on == 1 ? loger(cursor) : 0;
}