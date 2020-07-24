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
# define REG_LEN		1

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

t_vm		*init_vm();
t_player	*init_player(int id);
void		init_arena(t_vm *vm);
t_cursor	*init_cursor(t_player *player, int pos);
void		set_cursors(t_vm *vm);
int			load_players_to_vm(t_vm *vm, t_player *players_list);

/*
** Args and getopts funcs
*/

void		parse_args(int ac, char **av);
int			find_addr(int addr);

/*typedef struct	s_op
{
	char		*name;
	uint8_t		code;
	uint8_t		args_num;
	int			args_types_code;
	uint8_t		args_types[3];
	uint8_t		t_dir_size;
}				t_op;

static t_op		g_op[16] = {
	{
		name = "live",
		code = 0x01,
		args_num = 1,
		args_types_code = 0,
		args_types = {T_DIR, 0, 0},	
		modify_carry = false,
		t_dir_size = 4,
		cycles = 10, 
		func = &op_live
	},
	{
		name = "ld",
		code = 0x02,
		args_num = 2,
		args_types_code = 1,
		args_types = {T_DIR | T_IND, T_REG, 0},
		modify_carry = true,
		t_dir_size = 4,
		cycles = 5,
		func = &op_ld
	},
	{
		name = "st",
		code = 0x03,
		args_num = 2,
		args_types_code = 1,
		args_types = {T_REG, T_REG | T_IND, 0},
		modify_carry = false,
		t_dir_size = 4t_cursor *dupl_cur(t_cursor *cur, int addr)
		cycles = 5,
		func = &op_st
	},
	{
		name = "add",
		code = 0x04,
		args_num = 3,
		posargs_types_code = 1,
		args_types = {T_REG, T_REG, T_REG},
		modify_carry = true,
		t_dir_size = 4,
		cycles = 10,
		func = &op_add
	},
	{
		name = "sub",# define REG_LEN		1
		args_num = 3,
		posargs_types_code = 1,
		args_types = {T_REG, T_REG, T_REG},
		modify_carry = true,
		t_dir_size = 4,
		cycles = 10,
		func = &op_sub
	},# define REG_LEN		1
		name = "or",
		code = 0x07,
		args_num = 3,
		posargs_types_code = 1,
		args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		modify_carry = true,
		t_dir_size = 4,
		cycles = 6,
		func = &op_or
	},
	{
		name = "xor",
		code = 0x08,
		args_num = 3,
		posargs_types_code = 1,
		args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		modify_carry = true,
		t_dir_size = 4,
		cycles = 6,
		func = &op_xor
	},
	{
		name = "zjmp",
		code = 0x09,
		args_num = 1,
		posargs_typest_cursor *dupl_cur(t_cursor *cur, int addr)
		func = &op_zjmp
	},
	{
		name = "ldi",
		code = 0x0A,
		args_num = 3,
		posargs_types_code = 1,
		args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		modify_carry = false,
		t_dir_size = 2,void	set_cursors(t_vm *vm)
	{
		name = "sti",
		code = 0x0B,
		args_num = 3,
		posargs_types_code = 1,
		args_types = {T_REG, T_REG | Tvoid	set_cursors(t_vm *vm)_DIR | T_IND, T_REG | T_DIR},
		modify_carry = false,
		t_dir_size = 2,
		cycles = 25,
		func = &op_sti
	},
	{
		name = "fork",
		code = 0x0C,
		args_num = 1,
		posargs_types_code = 0,
		args_types = {T_DIR, 0, 0},
		modify_carry = false,
		t_dir_size = 2,
		cycles = 800,
		func = &op_fork
	},
	{
		name = "lld",
		code = 0x0D,
		args_num = 2,
		posargs_types_code = 1,
		args_types = {T_DIR | T_IND,void	set_cursors(t_vm *vm)
		func = &op_lld
	},
	{
		name = "lldi",
		code = 0x0E,
		args_num = 3,
		posargs_types_code = 1,
		args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		modify_carry = true,
		t_dir_size = 2,
		cycles = 50,
		func = &op_lldi
	},
	{
		name = "lfork",
		code = 0x0F,du
		args_types = {T_DIR, 0, 0},
		modify_carry = false,
		t_dir_size = 2,
		cycles = 1000,void	set_cursors(t_vm *vm)
		name = "aff",
		code = 0x10,
		args_num = 1,#include "corewar.h"
		posargs_types_code = 1,
		args_types = {T_REG, 0, 0},
		modify_carry = false,
		t_dir_size = 4,
		cycles = 2,
		func = &op_aff
	}
};*/

/*du
void			op_ld(t_vm *vm, t_cursor *cursor);
void			op_st(t_vm *vm, t_cursor *cursor);
void			op_add(t_vm *vm, t_cursor *cursor);
void			op_sub(t_vm *vm, t_cuvoid	set_cursors(t_vm *vm)rsor *cursor);
void			op_and(t_vm *vm, t_cursor *cursor);
void			op_or(t_vm *vm, t_cursor duor *cursor);
void			op_lldi(t_vm *vm, t_cursor *cursor);
void			op_lfork(t_vm *vm, t_cursor *cursor);
void			op_aff(t_vm *vm, t_cursor *cursor);

/*
** additional functions
*/

int			get_arg(t_vm *vm, t_cursor *cursor, int index, int mod);
int			find_addr(int addr);
int32_t		bytecode_to_int32(const uint8_t *arena, int32_t addr, int32_t size);
void		int32_to_bytecode(uint8_t *arena, int32_t addr, int32_t value,
							int32_t size);
int 		get_byte(int addr, t_vm *vm);
int			step_size(uint8_t arg_type, int dir_size);
int			get_arg(t_vm *vm, t_cursor *cursor, int index, int mod);
int			get_dir_size(int op_code);
t_cursor	*dupl_cur(t_cursor *cur, int addr);
#endif
