//
// Created by Aileen Olen on 8/30/20.
//
#include "corewar.h"


void parse_verbal_type(int verbal_type)
{
	g_flags.verbal = verbal_type;
}

char *ft_getopts(char **av, int *i)
{
	if (av[*i][1] == '-')
	{
		if (ft_strequ(&av[*i][2], "stealth"))
			g_flags.stealth = 1;

	}
	else if (av[*i][1] == 'v')
		parse_verbal_type(ft_atoi(av[++(*i)]));
	else if (av[*i][1] == 'd')
		g_flags.dump = ft_atoi(av[++(*i)]);
	else if (av[*i][1] == 'n')
		g_flags.player_num = ft_atoi(av[++(*i)]);
	else
		return (av[*i]);
	return (NULL);
}