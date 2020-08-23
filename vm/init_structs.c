//
// Created by poligon on 18.05.2020.
//

# include "corewar.h"
#include "includes/corewar.h"

t_player *init_player(int id)
{
	t_player *player;
	int i;

	i = 0;
	if (!(player = ft_memalloc(sizeof(*player))))
		error_exit(INTERNAL_ERROR, "");
	player->id = id;
	return player;
}

t_vm *init_vm()
{
	t_vm *vm;
	int i;

	i = -1;
	if (!(vm = ft_memalloc(sizeof(*vm))))
		error_exit(INTERNAL_ERROR, "");
	vm->cycles_to_die = CYCLE_TO_DIE;
	vm->display_aff = 0; // Здесь какойто иф исходя их флагов
	while (++i <= MAX_PLAYERS)
		vm->players[i] = NULL;
	return vm;
}

void init_arena(t_vm *vm)
{
	int id;
	int code_pos;

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

t_cursor *init_cursor(t_player *player, int pos)
{
	t_cursor *cursor;
	static size_t cursor_id = 0;

	if (!(cursor = ft_memalloc(sizeof(*cursor))))
		error_exit(INTERNAL_ERROR, "");
	cursor->id = cursor_id;
	cursor->pos = pos;
	cursor->reg[0] = -(player->id);
	cursor->player = player;
	return (cursor);
}