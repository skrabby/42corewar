/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 13:13:38 by oelaina           #+#    #+#             */
/*   Updated: 2020/08/15 13:34:38 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_ld(t_vm *vm, t_cursor *cursor)
{
	int	value;
	int	reg;

	cursor->step += (OP_CODE_LEN + ARGS_CODE_LEN);
	value = get_arg(vm, cursor, 1, 1);
	if (value == 0)
		cursor->carry = 1;
	else
		cursor->carry = 0;
	reg = get_byte(cursor->pos + cursor->step, vm);
	cursor->reg[reg - 1] = value;
	cursor->step += REG_LEN;
}
