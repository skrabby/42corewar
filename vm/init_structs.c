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

	if (!(vm = ft_memalloc(sizeof(*vm))))
		error_exit(INTERNAL_ERROR, "");
	vm->cycles_to_die = CYCLE_TO_DIE;
	vm->dump_cycle = -1;
	vm->show_cycle = -1;
	return vm;
}