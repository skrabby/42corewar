/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 14:13:12 by oelaina           #+#    #+#             */
/*   Updated: 2020/09/20 17:12:54 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	parse_verbal_type(int verbal_type)
{
	g_flags.verbal = verbal_type;
}

static int	parse_player_num(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

int			ft_getopts(char **av, int ac, int *i)
{
	g_flags.dump = 0;
	if (av[*i][1] == '-')
	{
		if (ft_strequ(&av[*i][2], "stealth"))
			g_flags.stealth = 1;
	} else if ((*i + 1) < ac)
	{
		if (ft_strequ(&av[*i][1], "v"))
			parse_verbal_type(ft_atoi(av[++(*i)]));
		if (ft_strequ(&av[*i][1], "a"))
			g_flags.aff = 1;
		else if (ft_strequ(&av[*i][1], "d") || ft_strequ(&av[*i][1], "dump"))
			g_flags.dump = ft_atoi(av[++(*i)]);
		else if (ft_strequ(&av[*i][1], "n"))
			g_flags.player_num = parse_player_num(ft_atoi(av[++(*i)]));
	} else
		return (0);
	return (1);
}
