//
// Created by poligon on 18.05.2020.
//

#include "corewar.h"
#include <fcntl.h>



// TODO:
// 	- Implement -n flag and read 3 lines
int check_player(char **av, int i, t_player **players_list, int id)
{
	if (str_endswith(av[i], CHAMP_EXT))
		read_champion_file(av[i], id);
	else
		print_usage(av[0]);
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
			check_player(av, i, &players_list, 0);
}