/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 13:14:07 by oelaina           #+#    #+#             */
/*   Updated: 2020/08/15 13:39:35 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_lld(t_vm *vm, t_cursor *cursor)
{
	int val;
	int reg;

	cursor->step += OP_CODE_LEN + ARGS_CODE_LEN;
	val = get_arg(vm, cursor, 1, 1);
	if (val == 0)
		cursor->carry = 1;
	else
		cursor->carry = 0;
	reg = get_byte(cursor->pos + cursor->step, vm);
	cursor->reg[reg - 1] = val;
	cursor->step += REG_LEN;
}
