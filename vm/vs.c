/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 14:13:23 by oelaina           #+#    #+#             */
/*   Updated: 2020/09/05 14:13:24 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	vs_map(t_cursor *cursor)
{
	int i;

	i = 0;
	while (i < 100)
	{
		if (i == (int)cursor->pos)
			ft_printf("%d -->", cursor->id);
		if (i % 32 != 0 || i == 0)
		{
			ft_printf("{red}%d{green}(%d) ", g_vm->arena[i], i);
			i++;
		}
		else
		{
			ft_printf("{red}%d{green}(%d) ", g_vm->arena[i], i);
			ft_printf("\n");
			i++;
		}
	}
	i = 0;
	while (i < 10)
	{
		ft_printf("\n");
		i++;
	}
}
