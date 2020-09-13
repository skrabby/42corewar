/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 14:17:26 by oelaina           #+#    #+#             */
/*   Updated: 2020/09/05 14:17:26 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int8_t			pow_to_cursor_type(int pow, int base)
{
	int8_t res;

	if (pow == -1)
		return (0);
	res = 1;
	while (pow-- > 0)
	{
		res *= base;
	}
	return (res);
}

void			parse_types_code(t_vm *vm, t_cursor *cursor, t_op *op)
{
	int8_t args_types_code;

	if (op->args_types_code)
	{
		args_types_code = get_byte_from_arena(vm, cursor->pos, 1);
		if (op->args_num >= 1)
			cursor->args_types[0] = pow_to_cursor_type(
					(int8_t)((args_types_code & FIRST_ARG_MASK) >> 6) - 1, 2);
		if (op->args_num >= 2)
			cursor->args_types[1] = pow_to_cursor_type(
					(int8_t)((args_types_code & SECOND_ARG_MASK) >> 4) - 1, 2);
		if (op->args_num >= 3)
			cursor->args_types[2] = pow_to_cursor_type(
					(int8_t)((args_types_code & THIRD_ARG_MASK) >> 2) - 1, 2);
	}
	else
		cursor->args_types[0] = op->args_types[0];
}

void			int_to_bytecode(uint8_t *arena, int addr, int value,
						int size)
{
	int i;

	i = 0;
	while (size)
	{
		arena[find_addr(addr + size - 1)] = (uint8_t)((value >> i) & 0xFF);
		i += 8;
		size--;
	}
}
