//
// Created by poligon on 18.05.2020.
//

#include "corewar.h"
#include <fcntl.h>



// TODO:
// 	- Implement -n flag and read 3 lines
int parse_player(char **av, int i, t_player **players_list, int id)
{
	t_player *iter;

	iter = *players_list;
	if (str_endswith(av[i], CHAMP_EXT))
	{
		if (!*players_list)
			*players_list = read_champion_file(av[i], i);
		else
		{
			while (iter->next)
				iter = iter->next;
			iter->next = read_champion_file(av[i], i);
		}
	}
	else
		print_usage(av[0]);
	g_vm->players_num++;
	return (0);
}

void parse_args(int ac, char **av)
{
	int i;
	t_player *players_list;

	i = 0;
	players_list = NULL;
	if (ac == 1)
		print_usage(av[0]);
	while (++i < ac)
		if (av[i][0] == '-')
			;
//			ft_getopts(av[i]);
		else
			parse_player(av, i, &players_list, 0);
	load_players_to_vm(g_vm, players_list);
}