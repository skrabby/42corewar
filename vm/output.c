/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 14:13:15 by oelaina           #+#    #+#             */
/*   Updated: 2020/09/05 14:13:15 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char	*get_memory_index(int bytes_num)
{
	char	symbols[4];
	char	*result;
	int		i;

	i = -1;
	result = ft_strnew(7);
	symbols[0] = HEX[bytes_num / BASE_3];
	symbols[1] = HEX[(bytes_num % BASE_3) / BASE_2];
	symbols[2] = HEX[(bytes_num % BASE_2) / BASE_1];
	symbols[3] = HEX[(bytes_num % BASE_1) / BASE_0];
	result[0] = '0';
	result[1] = 'x';
	while (++i < 4)
	{
		result[i + STEP] = symbols[i];
	}
	return (result);
}

void	print_arena(t_vm *vm)
{
	int		i;
	char	*hex;

	i = 0;
	hex = HEX;
	ft_printf("%s : ", get_memory_index(i));
	while (i < MEM_SIZE)
	{
		if ((i % (PRINT_SIZE / 2) == 0) && (i / (PRINT_SIZE / 2) > 0))
		{
			ft_printf("\n");
			ft_printf("%s : ", get_memory_index(i));
		}
		ft_printf("%c%c ", hex[vm->arena[i] / 16], hex[vm->arena[i] % 16]);
		i++;
	}
}

void	print_intro(t_vm *vm)
{
	int i;

	i = FIRST_CHAMP_ID - 1;
	ft_printf("Introducing contestants...\n");
	while (++i <= vm->players_num)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
				i, vm->players[i]->code_size, vm->players[i]->name,
					vm->players[i]->comment);
	}
}

void	print_winner(t_vm *vm)
{
	ft_printf("Contestant %d, \"%s\", has won !\n",
				vm->last_alive->id,
				vm->last_alive->name);
}
