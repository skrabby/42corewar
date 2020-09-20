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

static void	find_free_place(t_vm *vm, t_player *players)
{
	int id;

	id = FIRST_CHAMP_ID;
	while (!vm->players[id])
	{
		id++;
	}
	if (id > 0 && id <= MAX_PLAYERS)
		players->id = id;
	else
		error_exit(MANY_CHAMPS_ERROR, "Find free place");
}

static void place_champs(t_vm *vm, t_player *iter)
{
	while (iter)
	{
		if (iter->id != 0)
		{
			if (!(vm->players[iter->id]))
				vm->players[iter->id] = iter;
			else
			{
				find_free_place(vm, iter);
				vm->players[iter->id] = iter;
			}
		}
		iter = iter->next;
	}
}

int load_players_to_vm(t_vm *vm, t_player *players_list)
{
	int i;

	i = FIRST_CHAMP_ID;
	place_champs(vm, players_list);
	while (players_list && (i <= vm->players_num))
	{
		if (!vm->players[i])
		{
			if (players_list->id <= 0 || players_list->id > MAX_PLAYERS)
			{
				vm->players[i] = players_list;
				vm->players[i]->id = i;
			}
			players_list = players_list->next;
		}
		else
			i++;
	}
	if (vm->players_num > MAX_PLAYERS)
		error_exit(MANY_CHAMPS_ERROR, "");
	i = FIRST_CHAMP_ID - 1;
	while (++i < MAX_PLAYERS)
		vm->last_alive = vm->players[i] ? vm->players[vm->players_num] :
						 vm->last_alive;
	return (0);
}
