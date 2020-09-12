/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycles_to_die.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 14:12:22 by oelaina           #+#    #+#             */
/*   Updated: 2020/09/05 14:12:22 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		reset_lives_nums(t_vm *vm)
{
	int32_t		i;

	i = FIRST_CHAMP_ID - 1;
	while (++i <= MAX_PLAYERS)
	{
		if (!(vm->players[i]))
			continue ;
		vm->players[i]->previous_lives_num = vm->players[i]->current_lives_num;
		vm->players[i]->current_lives_num = 0;
	}
	vm->lives_num = 0;
}

static uint8_t	is_died(t_vm *vm, t_cursor *cursor)
{
	return (vm->cycles_to_die <= 0
			|| vm->cycles - cursor->last_live >= vm->cycles_to_die);
}

static void		delete_died_cursors(t_vm *vm)
{
	t_cursor	*previous;
	t_cursor	*current;
	t_cursor	*delete;

	previous = NULL;
	current = vm->cursors;
	while (current)
		if (is_died(vm, (delete = current)) && vm->cursors_num--)
		{
			current = current->next;
			if (vm->cursors == delete)
				vm->cursors = current;
			if (previous)
				previous->next = current;
			ft_memdel((void **)&delete);
		}
		else
		{
			previous = current;
			current = current->next;
		}
}

void			cycles_to_die_check(t_vm *vm)
{
	vm->checks_num++;
	delete_died_cursors(vm);
	if (vm->checks_num == MAX_CHECKS || vm->lives_num >= NBR_LIVE)
	{
		vm->cycles_to_die -= CYCLE_DELTA;
		if (vm->v2 == 1)
			ft_printf("Cycle to die is now %d\n", (int)vm->cycles_to_die);
		vm->checks_num = 0;
	}
	reset_lives_nums(vm);
	vm->cycles_after_check = 0;
}
