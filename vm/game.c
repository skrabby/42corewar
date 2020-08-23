//
// Created by poligon on 19.07.2020.
//

#include "corewar.h"

void read_op(t_cursor *cursor, t_vm *vm)
{
	cursor->op_code = vm->arena[cursor->pos];
	if (cursor->op_code >= 0x01 && cursor->op_code <= 0x10)
		cursor->cycles_to_exec = g_op[cursor->op_code - 1].cycles;
}

void	move_cursor(t_vm *vm, t_cursor *cursor)
{
	cursor->pos += cursor->step;
	cursor->pos = check_position(cursor->pos);
	cursor->step = 0;
	ft_bzero(cursor->args_types, 3);
}

static void exec_code(t_cursor *cursor, t_vm *vm)
{
	t_op *op;

	if (cursor->cycles_to_exec == 0)
		read_op(cursor, vm);
	if (cursor->cycles_to_exec > 0)
		cursor->cycles_to_exec--;
	if (cursor->cycles_to_exec == 0)
	{
		op = NULL;
		if (cursor->op_code >= 0x01 && cursor->op_code <= 0x10)
			op = &g_op[cursor->op_code - 1];
		if (op)
		{
			parse_types_code(vm, cursor, op);
			if (is_arg_types_valid(cursor, op) && is_args_valid(cursor, vm, op))
				op->func(vm, cursor);
			else
				cursor->step += calc_step(cursor, op);
		}
		else
			cursor->step = OP_CODE_LEN;
		move_cursor(vm, cursor);
        //vs_map(cursor);
	}
}

static void exec_cycle(t_vm *vm)
{
	t_cursor *curr_cursor;

	vm->cycles++;
	vm->cycles_after_check++;
	// logging
	curr_cursor = vm->cursors;
	while (curr_cursor)
	{
		exec_code(curr_cursor, vm);
		curr_cursor = curr_cursor->next;
	}
}

void fight(t_vm *vm)
{
	while (vm->cursors_num)
	{
		exec_cycle(vm);
        if (vm->cycles_to_die == vm->cycles_after_check
            || vm->cycles_to_die <= 0)
            cycles_to_die_check(vm);
	}
}