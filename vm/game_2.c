//
// Created by poligon on 22.07.2020.
//

#define FIRST_ARG_MASK 192
#define SECOND_ARG_MASK 48
#define THIRD_ARG_MASK 12
#define CODE_LEN 1
#define ARGS_LEN 1
#define REG_LEN 1


#include "corewar.h"
#include "op.h"

int check_position(int position)
{
	position = position % MEM_SIZE;
	if (position < 0)
		position += MEM_SIZE;
	return position;
}

int8_t get_byte_from_arena(t_vm *vm, int position, int step)
{
	return (vm->arena[check_position(position + step)]);
}

void parse_types_code(t_vm *vm, t_cursor *cursor, t_op *op)
{
	int8_t args_types_code;

	if (op->args_types_code)
	{
		args_types_code = get_byte_from_arena(vm, cursor->pos, 1);
		if (op->args_num >= 1)
			cursor->args_types[0] = (int8_t) ((args_types_code & FIRST_ARG_MASK)
					>> 6);
		if (op->args_num >= 2)
			cursor->args_types[1] = (int8_t) (
					(args_types_code & SECOND_ARG_MASK) >> 4);
		if (op->args_num >= 3)
			cursor->args_types[2] = (int8_t) ((args_types_code & THIRD_ARG_MASK)
					>> 2);
	} else
		cursor->args_types[0] = op->args_types[0];
}

uint8_t		is_arg_types_valid(t_cursor *cursor, t_op *op)
{
	int i;

	i = -1;
	while (++i < op->args_num)
		if (!(cursor->args_types[i] & op->args_types[i]))
			return (0);
	return (1);
}

static uint8_t	is_register(t_vm *vm, int32_t pos, int32_t step)
{
	int8_t r_id;

	r_id = get_byte_from_arena(vm, pos, step);
	return (r_id >= 1 && r_id <= REG_NUMBER);
}



uint8_t		is_args_valid(t_cursor *cursor,t_vm *vm, t_op *op)
{
	int i;
	int step;

	i = -1;
	step = (CODE_LEN + (op->args_types_code ? ARGS_LEN : 0));
	while (++i < op->args_num)
	{
		if ((cursor->args_types[i] == T_REG)
			&& !is_register(vm, cursor->pos, step))
			return (0);
		step += step_size(cursor->args_types[i], op);
		i++;
	}
	return (1);
}