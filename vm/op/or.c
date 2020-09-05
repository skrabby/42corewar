/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 12:28:41 by oelaina           #+#    #+#             */
/*   Updated: 2020/09/05 12:28:41 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_or(t_vm *vm, t_cursor *cursor)
{
	int val1;
	int val2;
	int res;
	int reg;

	cursor->step += (OP_CODE_LEN + ARGS_CODE_LEN);
	val1 = get_arg(vm, cursor, 1, 1);
	val2 = get_arg(vm, cursor, 2, 1);
	res = val1 | val2;
	if (res == 0)
		cursor->carry = 1;
	else
		cursor->carry = 0;
	reg = get_byte(cursor->pos + cursor->step, vm);
	cursor->reg[reg - 1] = res;
	cursor->step += REG_LEN;
	vm->loger_on == 1 ? ft_printf("P %4d | or %d %d r%d\n",
									cursor->id, val1, val2, reg) : 0;
}
