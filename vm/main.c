//
// Created by poligon on 18.05.2020.
//

#include "corewar.h"
#include <errno.h>

int main(int ac, char **av)
{
	if (ac <= 1)
		print_usage(av[0]);
	g_vm = init_vm();
    parse_args(ac, av);
    init_arena(g_vm);
    set_cursors(g_vm);
	ft_printf("Prog done!!!\n");
	return (0);
}
