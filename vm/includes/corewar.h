//
// Created by poligon on 18.05.2020.
//

#ifndef COREWAR_H
# define COREWAR_H

# include <stdint.h>
# include <libft.h>
# include "op.h"
# include "errors.h"

/*
** Consts
*/

# define CHAMP_EXT ".cor"
# define FIRST_CHAMP_ID 1

/*
** Structs
*/

typedef struct			s_player
{
	int32_t				id;
	char				*name;
	char				*comment;
	int32_t				code_size;
	uint8_t				*code;
	size_t				current_lives_num;
	size_t				previous_lives_num;
	ssize_t				last_live;
	struct s_player		*next;
}						t_player;

typedef struct			s_cursor
{
	uint32_t			id;
	uint8_t				carry;
	uint8_t				op_code;
	ssize_t				last_live;
	int					cycles_to_exec;
	uint8_t				args_types[3];
	int32_t				pos;
	uint32_t			step;
	int32_t				reg[REG_NUMBER];
	t_player			*player;
	struct s_cursor		*next;
}						t_cursor;

typedef struct			s_vm
{
	uint8_t				arena[MEM_SIZE];
	t_player			*players[MAX_PLAYERS + 1];
	int32_t				players_num;
	t_player			*last_alive;
	t_cursor			*cursors;
	size_t				cursors_num;
	size_t				lives_num;
	ssize_t				cycles;
	ssize_t				cycles_to_die;
	ssize_t				cycles_after_check;
	size_t				checks_num;
}						t_vm;

/*
** Globals
*/

t_vm *g_vm;

/*
** Funcs
*/
void print_usage(char *filename);
void error_exit(char *message, char *filename);
int str_endswith(char *str, char *end);

t_player *read_champion_file(char *filename, int id);

/*
** Init funcs
*/

t_vm *init_vm();
t_player *init_player(int id);
void init_arena(t_vm *vm);
t_cursor *init_cursor(t_player *player, int pos);
void set_cursors(t_vm *vm);
int load_players_to_vm(t_vm *vm, t_player *players_list);

/*
** Args and getopts funcs
*/

void parse_args(int ac, char **av);

#endif
