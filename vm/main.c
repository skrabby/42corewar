//
// Created by poligon on 18.05.2020.
//

#include "corewar.h"
#include <errno.h>

#define FT_ABS(x) x > 0 ? x : -x


static void	print_last_alive(t_vm *vm)
{
    ft_printf("Contestant %d, \"%s\", has won !\n",
              FT_ABS(vm->last_alive->id),
              vm->last_alive->name);
}

int main(int ac, char **av)
{
	if (ac <= 1)
		print_usage(av[0]);
	g_vm = init_vm();
    parse_args(ac, av);
    init_arena(g_vm);
    set_cursors(g_vm);
	print_intro(g_vm);
	fight(g_vm);
    print_last_alive(g_vm);
	return (0);
}
