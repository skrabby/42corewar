/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 14:12:17 by oelaina           #+#    #+#             */
/*   Updated: 2020/09/05 14:12:17 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		set_cursors(t_vm *vm)
{
	int			id;
	size_t		pos;
	t_cursor	*cursor_ptr;

	id = FIRST_CHAMP_ID;
	pos = 0;
	while (id <= vm->players_num)
	{
		if (!vm->cursors)
			vm->cursors = init_cursor(vm->players[id], pos);
		else
		{
			cursor_ptr = init_cursor(vm->players[id], pos);
			cursor_ptr->next = vm->cursors;
			vm->cursors = cursor_ptr;
		}
		vm->cursors_num++;
		pos += MEM_SIZE / vm->players_num;
		id++;
	}
}

t_cursor	*dupl_cur(t_cursor *cur, int addr)
{
	t_cursor	*new;
	int			i;

	addr = find_addr(cur->pos + addr);
	new = init_cursor(cur->player, addr);
	i = 0;
	while (i < REG_NUMBER)
	{
		new->reg[i] = cur->reg[i];
		i++;
	}
	new->carry = cur->carry;
	new->last_live = cur->last_live;
	return (new);
}

void		add_cur(t_cursor **list, t_cursor *cur)
{
	if (cur)
		cur->next = *list;
	*list = cur;
}
