/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 13:14:01 by oelaina           #+#    #+#             */
/*   Updated: 2020/08/15 13:38:39 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_live(t_vm *vm, t_cursor *cursor)
{
	int			pl_id;
	t_player	*pl;

	cursor->step += OP_CODE_LEN;
	pl_id = get_arg(vm, cursor, 1, 0);
	vm->lives_num++;
	cursor->last_live = vm->cycles;
	pl = NULL;
	if (pl_id <= -1 && pl_id >= -vm->players_num)
	{
		pl = vm->players[pl_id];
		pl->last_live = vm->cycles;
		pl->current_lives_num++;
		vm->last_alive = pl;
	}
}
