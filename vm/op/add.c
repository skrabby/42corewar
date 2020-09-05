/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 12:27:50 by oelaina           #+#    #+#             */
/*   Updated: 2020/09/05 12:27:53 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_add(t_vm *vm, t_cursor *cursor)
{
	int reg1;
	int reg2;
	int reg3;
	int value;

	cursor->step += (OP_CODE_LEN + ARGS_CODE_LEN);
	reg1 = get_byte(cursor->pos + cursor->step, vm);
	cursor->step += REG_LEN;
	reg2 = get_byte(cursor->pos + cursor->step, vm);
	cursor->step += REG_LEN;
	value = cursor->reg[reg1 - 1] + cursor->reg[reg2 - 1];
	if (value == 0)
		cursor->carry = 1;
	else
		cursor->carry = 0;
	reg3 = get_byte(cursor->pos + cursor->step, vm);
	cursor->reg[reg3 - 1] = value;
	cursor->step += REG_LEN;
	vm->loger_on == 1 ? ft_printf("P %4d | add r%d r%d r%d\n",
								cursor->id, reg1, reg2, reg3) : 0;
}
