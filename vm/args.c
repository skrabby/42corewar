/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 14:11:57 by oelaina           #+#    #+#             */
/*   Updated: 2020/09/05 14:11:58 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <fcntl.h>

int		parse_player(char **av, int i, t_player **players_list, int id)
{
	t_player	*iter;

	iter = *players_list;
	if (str_endswith(av[i], CHAMP_EXT))
	{
		if (!*players_list)
			*players_list = read_champion_file(av[i], id);
		else
		{
			while (iter->next)
				iter = iter->next;
			iter->next = read_champion_file(av[i], id);
		}
	}
	else
		print_usage(av[0]);
	g_vm->players_num++;
	g_flags.player_num = 0;
	return (0);
}

void	parse_args(int ac, char **av)
{
	int			i;
	t_player	*players_list;

	i = 0;
	players_list = NULL;
	if (ac == 1)
		print_usage(av[0]);
	while (++i < ac)
		if ((av[i][0] == '-') && ft_getopts(av, ac, &i))
			;
		else
			parse_player(av, i, &players_list, g_flags.player_num);
	load_players_to_vm(g_vm, players_list);
}
