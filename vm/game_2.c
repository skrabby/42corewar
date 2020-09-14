/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 14:12:49 by oelaina           #+#    #+#             */
/*   Updated: 2020/09/05 14:12:49 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "op.h"

uint8_t			is_arg_types_valid(t_cursor *cursor, t_op *op)
{
	int i;

	i = -1;
	while (++i < op->args_num)
		if (!(cursor->args_types[i] & op->args_types[i]))
			return (0);
	return (1);
}

int				check_position(int position)
{
	position = position % MEM_SIZE;
	if (position < 0)
		position += MEM_SIZE;
	return (position);
}

int8_t			get_byte_from_arena(t_vm *vm, int position, int step)
{
	return (vm->arena[check_position(position + step)]);
}

static uint8_t	is_register(t_vm *vm, int32_t pos, int32_t step)
{
	int8_t r_id;

	r_id = get_byte_from_arena(vm, pos, step);
	return (r_id >= 1 && r_id <= REG_NUMBER);
}

uint8_t			is_args_valid(t_cursor *cursor, t_vm *vm, t_op *op)
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
	}
	return (1);
}
