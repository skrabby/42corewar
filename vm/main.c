//
// Created by poligon on 18.05.2020.
//

#include "corewar.h"

int main(int ac, char **av)
{
	g_vm = ft_memalloc(sizeof(*g_vm));
    check_args(ac, av);
}