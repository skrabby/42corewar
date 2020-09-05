/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champs_to_vm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 14:12:13 by oelaina           #+#    #+#             */
/*   Updated: 2020/09/05 14:12:14 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		place_champs(t_vm *vm, t_player *iter)
{
	while (iter)
	{
		if (iter->id != 0)
		{
			if (!(vm->players[iter->id]))
				vm->players[iter->id] = iter;
			else
				error_exit(DOUBLE_INDEX_ERROR, "");
		}
		iter = iter->next;
	}
}

int				load_players_to_vm(t_vm *vm, t_player *players_list)
{
	int i;

	i = FIRST_CHAMP_ID;
	place_champs(vm, players_list);
//	while (players_list && i++ <= MAX_PLAYERS)
//	{
//		if (!vm->players[i])
//			vm->players[i] = players_list;
//		else
//			continue ;
//		players_list = players_list->next;
//	}
//	if (players_list)
//		error_exit(MANY_CHAMPS_ERROR, "");
	vm->last_alive = vm->players[vm->players_num];
	return (0);
}
