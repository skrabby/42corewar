/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 12:28:03 by oelaina           #+#    #+#             */
/*   Updated: 2020/09/05 12:28:04 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_aff(t_vm *vm, t_cursor *cursor)
{
	int reg;
	int val;

	cursor->step += (OP_CODE_LEN + ARGS_CODE_LEN);
	reg = get_byte(cursor->pos + cursor->step, vm);
	val = cursor->reg[reg - 1];
	cursor->step += REG_LEN;
	if (g_flags.aff)
		ft_printf("Aff: %c\n", (char)val);
}
