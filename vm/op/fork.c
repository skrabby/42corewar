#include "corewar.h"

void    op_fork(t_vm *vm, t_cursor *cursor)
{
	int         val;
	t_cursor	*new_cur;

	cursor->step += OP_CODE_LEN;
	val = get_arg(vm, cursor, 1, 1);
	new_cur = dupl_cur(cursor, val % IDX_MOD);
	add_cur(&(vm->cursors), new_cur);
	vm->cursors_num++;
	//vs_map(cursor);
    vm->loger_on == 1 ? loger(cursor) : 0;
}