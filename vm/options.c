/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 14:13:12 by oelaina           #+#    #+#             */
/*   Updated: 2020/09/05 14:13:12 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	parse_verbal_type(int verbal_type)
{
	g_flags.verbal = verbal_type;
}

int ft_getopts(char **av, int ac, int *i)
{
	if (av[*i][1] == '-')
	{
		if (ft_strequ(&av[*i][2], "stealth"))
			g_flags.stealth = 1;
	}
	else if ((*i + 1) < ac)
	{
		if (av[*i][1] == 'v')
			parse_verbal_type(ft_atoi(av[++(*i)]));
		else if (av[*i][1] == 'd')
			g_flags.dump = ft_atoi(av[++(*i)]);
		else if (av[*i][1] == 'n')
			g_flags.player_num = ft_atoi(av[++(*i)]);
	}
	else
		return (0);
	return (1);
}
