//
// Created by poligon on 12.07.2020.
//

#include "corewar.h"

#define HEX "0123456789ABCDEF"
#define PRINT_SIZE 128

void print_arena(t_vm *vm)
{
	int i;
	char *hex;

	i = 0;
	hex = HEX;
	while (i < MEM_SIZE)
	{
		if ((i % (PRINT_SIZE / 2) == 0) && (i / (PRINT_SIZE / 2) > 0))
			ft_printf("\n");
		ft_printf("%c%c ", hex[vm->arena[i] / 16], hex[vm->arena[i] % 16]);
		i++;
	}
}

void print_intro(t_vm *vm)
{
	int i;

	i = FIRST_CHAMP_ID - 1;
	ft_printf("Introducing contestants...\n");
	while (++i <= vm->players_num)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
				  i,
				  vm->players[i]->code_size,
				  vm->players[i]->name,
				  vm->players[i]->comment);
	}
}

void	print_winner(t_vm *vm)
{
	ft_printf("Contestant %d, \"%s\", has won !\n",
			  vm->last_alive->id,
			  vm->last_alive->name);
}