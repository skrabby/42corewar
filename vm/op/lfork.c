/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 12:28:26 by oelaina           #+#    #+#             */
/*   Updated: 2020/09/05 12:28:26 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_lfork(t_vm *vm, t_cursor *cursor)
{
	int			val;
	t_cursor	*new_cur;

	cursor->step += OP_CODE_LEN;
	val = get_arg(vm, cursor, 1, 1);
	new_cur = dupl_cur(cursor, val);
	add_cur(&(vm->cursors), new_cur);
	vm->cursors_num++;
	(g_flags.verbal & V_MASK_4) ? ft_printf("P %4d | lfork %d (%d)\n",
								cursor->id, val, cursor->pos + val) : 0;
}
