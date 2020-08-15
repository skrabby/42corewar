/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 13:08:48 by oelaina           #+#    #+#             */
/*   Updated: 2020/08/15 13:27:07 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_fork(t_vm *vm, t_cursor *cursor)
{
	int			val;
	t_cursor	*new_cur;

	cursor->step += OP_CODE_LEN;
	val = get_arg(vm, cursor, 1, 1);
	new_cur = dupl_cur(cursor, val % IDX_MOD);
	add_cur(&(vm->cursors), new_cur);
	vm->cursors_num++;
}
