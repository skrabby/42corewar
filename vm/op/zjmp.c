/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 13:14:53 by oelaina           #+#    #+#             */
/*   Updated: 2020/08/15 13:44:51 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				op_zjmp(t_vm *vm, t_cursor *cursor)
{
	int val;

	cursor->step += OP_CODE_LEN;
	val = get_arg(vm, cursor, 1, 1);
	if (cursor->carry == 1)
	{
		cursor->pos = find_addr(cursor->pos + (val % IDX_MOD));
		cursor->step = 0;
	}
	else
		return ;
}
