/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 14:12:53 by oelaina           #+#    #+#             */
/*   Updated: 2020/09/05 14:12:53 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_player		*init_player(int id)
{
	t_player	*player;
	int			i;

	i = 0;
	if (!(player = ft_memalloc(sizeof(*player))))
		error_exit(INTERNAL_ERROR, "");
	player->id = id;
	player->name = NULL;
	player->comment = NULL;
	player->code_size = 0;
	player->code = NULL;
	player->last_live = 0;
	player->current_lives_num = 0;
	player->previous_lives_num = 0;
	player->next = NULL;
	return (player);
}

t_vm			*init_vm(void)
{
	t_vm	*vm;
	int		i;

	i = -1;
	if (!(vm = ft_memalloc(sizeof(*vm))))
		error_exit(INTERNAL_ERROR, "");
	vm->cycles_to_die = CYCLE_TO_DIE;
	vm->display_aff = 0; // Здесь какойто иф исходя их флагов
	vm->lives_num = 0;
	vm->last_alive = NULL;
	vm->cursors = NULL;
	vm->cursors_num = 0;
	vm->cycles = 0;
	vm->cycles_after_check = 0;
	vm->checks_num = 0;
	vm->players_num = 0;
	vm->loger_on = 0;
	vm->v2 = 1;
	vm->dump_cycles = -1;
	while (++i <= MAX_PLAYERS)
		vm->players[i] = NULL;
	return (vm);
}

void			init_arena(t_vm *vm)
{
	int	id;
	int	code_pos;

	id = FIRST_CHAMP_ID;
	code_pos = 0;
	while (id <= MAX_PLAYERS)
	{
		if (vm->players[id])
		{
			ft_memcpy(&(vm->arena[code_pos]),
						vm->players[id]->code,
						vm->players[id]->code_size);
			code_pos += MEM_SIZE / vm->players_num;
		}
		id++;
	}
}

t_cursor		*init_cursor(t_player *player, int pos)
{
	t_cursor		*cursor;
	static size_t	cursor_id;

	cursor_id = 0;
	if (!(cursor = ft_memalloc(sizeof(*cursor))))
		error_exit(INTERNAL_ERROR, "");
	cursor->id = ++cursor_id;
	cursor->pos = pos;
	cursor->reg[0] = -(player->id);
	cursor->player = player;
	cursor->op_code = 0;
	cursor->last_live = 0;
	cursor->cycles_to_exec = 0;
	cursor->next = NULL;
	cursor->carry = 0;
	return (cursor);
}
