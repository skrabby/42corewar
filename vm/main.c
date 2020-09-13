/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 14:12:57 by oelaina           #+#    #+#             */
/*   Updated: 2020/09/05 14:12:57 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <errno.h>

static void	print_last_alive(t_vm *vm)
{
	ft_printf("Contestant %d, \"%s\", has won !\n",
				FT_ABS(vm->last_alive->id),
				vm->last_alive->name);
}

static void init_flags()
{
	g_flags.dump = -1;
	g_flags.verbal = 0;
	g_flags.aff = 0;
	g_flags.player_num = 0;
}

int			main(int ac, char **av)
{
	if (ac <= 1)
		print_usage(av[0]);
	g_vm = init_vm();
	parse_args(ac, av);
	init_flags();
	init_arena(g_vm);
	set_cursors(g_vm);
	print_intro(g_vm);
	fight(g_vm);
	print_last_alive(g_vm);
	return (0);
}
