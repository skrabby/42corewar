/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 12:28:08 by oelaina           #+#    #+#             */
/*   Updated: 2020/09/05 12:28:09 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_and(t_vm *vm, t_cursor *cursor)
{
	int val1;
	int val2;
	int res;
	int reg;

	cursor->step += (OP_CODE_LEN + ARGS_CODE_LEN);
	val1 = get_arg(vm, cursor, 1, 1);
	val2 = get_arg(vm, cursor, 2, 1);
	res = val1 & val2;
	if (res == 0)
		cursor->carry = 1;
	else
		cursor->carry = 0;
	reg = get_byte(cursor->pos + cursor->step, vm);
	cursor->reg[reg - 1] = res;
	cursor->step += REG_LEN;
	(g_flags.verbal & V_MASK_4) ? ft_printf("P %4d | and %d %d r%d\n",
									cursor->id, val1, val2, reg) : 0;
}
