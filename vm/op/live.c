/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 12:28:30 by oelaina           #+#    #+#             */
/*   Updated: 2020/09/05 12:28:30 by oelaina          ###   ########.fr       */
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
	if (pl_id <= -1 && pl_id >= -(MAX_PLAYERS) && vm->players[-pl_id])
	{

		pl = vm->players[pl_id < 0 ? -(pl_id) : pl_id];
		pl->last_live = vm->cycles;
		pl->current_lives_num++;
		vm->last_alive = pl;
		if(vm->v1 == 1)
			ft_printf("A process shows that player %d (%s) is alive\n",
													pl->id, pl->name);
	}
	(g_flags.verbal & V_MASK_4) ? ft_printf("P %4d | live %d\n", cursor->id, pl_id) : 0;
}
