//
// Created by poligon on 12.07.2020.
//

#include "corewar.h"

void set_cursors(t_vm *vm)
{
	int 	id;
	size_t 	pos;
	t_cursor *cursor_ptr;

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