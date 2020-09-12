/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 14:39:42 by oelaina           #+#    #+#             */
/*   Updated: 2020/09/05 14:39:43 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# define OP_CODE_LEN	1
# define ARGS_CODE_LEN	1

# define OP_CODE_LEN 1
# define ARGS_CODE_LEN 1

# define FIRST_ARG_MASK 192
# define SECOND_ARG_MASK 48
# define THIRD_ARG_MASK 12
# define CODE_LEN 1
# define ARGS_LEN 1

# define FT_ABS(x) x > 0 ? x : -x

# define HEX "0123456789abcdef"
# define PRINT_SIZE 128
# define ARENA_INDEX_BEGINING "0x"
# define STEP 2

# define BYTES

# define V_MASK_0 0
# define V_MASK_1 1
# define V_MASK_2 2
# define V_MASK_4 4
# define V_MASK_8 8
# define V_MASK_16 16


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
	int					display_aff;
	short				loger_on;
	short				v2;
	int					dump_cycles;
	int					v1;
}						t_vm;

typedef struct			s_flags
{
	uint8_t				verbal;
	unsigned int		dump;
	int8_t				stealth;
	int8_t				aff;
	int					player_num;
}						t_flags;

/*
** Globals
*/

t_vm *g_vm;
t_flags g_flags;

/*
** Funcs
*/
void					print_usage(char *filename);
void					error_exit(char *message, char *filename);
int						str_endswith(char *str, char *end);
t_player				*read_champion_file(char *filename, int id);

/*
** Init funcs
*/

t_vm					*init_vm();
t_player				*init_player(int id);
void					init_arena(t_vm *vm);
t_cursor				*init_cursor(t_player *player, int pos);
void					set_cursors(t_vm *vm);
int						load_players_to_vm(t_vm *vm, t_player *players_list);

void					op_live(t_vm *vm, t_cursor *pc);

void					op_ld(t_vm *vm, t_cursor *pc);

void					op_st(t_vm *vm, t_cursor *pc);

void					op_add(t_vm *vm, t_cursor *pc);

void					op_sub(t_vm *vm, t_cursor *pc);

void					op_and(t_vm *vm, t_cursor *cursor);

void					op_or(t_vm *vm, t_cursor *cursor);

void					op_xor(t_vm *vm, t_cursor *cursor);

void					op_zjmp(t_vm *vm, t_cursor *cursor);

void					op_ldi(t_vm *vm, t_cursor *cursor);

void					op_sti(t_vm *vm, t_cursor *cursor);

void					op_fork(t_vm *vm, t_cursor *cursor);

void					op_lld(t_vm *vm, t_cursor *cursor);

void					op_lldi(t_vm *vm, t_cursor *cursor);

void					op_lfork(t_vm *vm, t_cursor *cursor);

void					op_aff(t_vm *vm, t_cursor *cursor);

/*
** Args and getopts funcs
*/

void					parse_args(int ac, char **av);
int						find_addr(int addr);

typedef struct			s_op
{
	char				*name;
	uint8_t				code;
	uint8_t				args_num;
	short				args_types_code;
	uint8_t				args_types[3];
	short				modify_carry;
	uint8_t				t_dir_size;
	uint32_t			cycles;
	void				(*func)(t_vm *, t_cursor *);

}						t_op;

static t_op				g_op[16] = {
	{
		.name = "live",
		.code = 0x01,
		.args_num = 1,
		.args_types_code = 0,
		.args_types = {T_DIR, 0, 0},
		.modify_carry = 0,
		.t_dir_size = 4,
		.cycles = 10,
		.func = &op_live
	},
	{
		.name = "ld",
		.code = 0x02,
		.args_num = 2,
		.args_types_code = 1,
		.args_types = {T_DIR | T_IND, T_REG, 0},
		.modify_carry = 1,
		.t_dir_size = 4,
		.cycles = 5,
		.func = &op_ld
	},
	{
		.name = "st",
		.code = 0x03,
		.args_num = 2,
		.args_types_code = 1,
		.args_types = {T_REG, T_REG | T_IND, 0},
		.modify_carry = 0,
		.t_dir_size = 4,
		.cycles = 5,
		.func = &op_st
	},
	{
		.name = "add",
		.code = 0x04,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG, T_REG, T_REG},
		.modify_carry = 1,
		.t_dir_size = 4,
		.cycles = 10,
		.func = &op_add
	},
	{
		.name = "sub",
		.code = 0x05,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG, T_REG, T_REG},
		.modify_carry = 1,
		.t_dir_size = 4,
		.cycles = 10,
		.func = &op_sub
	},
	{
		.name = "and",
		.code = 0x06,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.modify_carry = 1,
		.t_dir_size = 4,
		.cycles = 6,
		.func = &op_and
	},
	{
		.name = "or",
		.code = 0x07,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.modify_carry = 1,
		.t_dir_size = 4,
		.cycles = 6,
		.func = &op_or
	},
	{
		.name = "xor",
		.code = 0x08,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.modify_carry = 1,
		.t_dir_size = 4,
		.cycles = 6,
		.func = &op_xor
	},
	{
		.name = "zjmp",
		.code = 0x09,
		.args_num = 1,
		.args_types_code = 0,
		.args_types = {T_DIR, 0, 0},
		.modify_carry = 0,
		.t_dir_size = 2,
		.cycles = 20,
		.func = &op_zjmp
	},
	{
		.name = "ldi",
		.code = 0x0A,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.modify_carry = 0,
		.t_dir_size = 2,
		.cycles = 25,
		.func = &op_ldi
	},
	{
		.name = "sti",
		.code = 0x0B,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG, T_REG | T_DIR | T_IND, T_REG | T_DIR},
		.modify_carry = 0,
		.t_dir_size = 2,
		.cycles = 25,
		.func = &op_sti
	},
	{
		.name = "fork",
		.code = 0x0C,
		.args_num = 1,
		.args_types_code = 0,
		.args_types = {T_DIR, 0, 0},
		.modify_carry = 0,
		.t_dir_size = 2,
		.cycles = 800,
		.func = &op_fork
	},
	{
		.name = "lld",
		.code = 0x0D,
		.args_num = 2,
		.args_types_code = 1,
		.args_types = {T_DIR | T_IND, T_REG, 0},
		.modify_carry = 1,
		.t_dir_size = 4,
		.cycles = 10,
		.func = &op_lld
	},
	{
		.name = "lldi",
		.code = 0x0E,
		.args_num = 3,
		.args_types_code = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.modify_carry = 1,
		.t_dir_size = 2,
		.cycles = 50,
		.func = &op_lldi
	},
	{
		.name = "lfork",
		.code = 0x0F,
		.args_num = 1,
		.args_types_code = 0,
		.args_types = {T_DIR, 0, 0},
		.modify_carry = 0,
		.t_dir_size = 2,
		.cycles = 1000,
		.func = &op_lfork
	},
	{
		.name = "aff",
		.code = 0x10,
		.args_num = 1,
		.args_types_code = 1,
		.args_types = {T_REG, 0, 0},
		.modify_carry = 0,
		.t_dir_size = 4,
		.cycles = 2,
		.func = &op_aff
	}
};

/*
** additional functions
*/

int						get_arg(t_vm *vm, t_cursor *cursor, int index, int mod);
int						find_addr(int addr);
int						bytecode_to_int_op(const uint8_t *arena,
							int addr, int size);
void					int_to_bytecode(uint8_t *arena, int addr, int value,
						int size);
int						get_byte(int addr, t_vm *vm);
int8_t					get_byte_from_arena(t_vm *vm, int position, int step);
int						step_size_op(uint8_t arg_type, int dir_size);
int						get_arg(t_vm *vm, t_cursor *cursor, int index, int mod);
t_cursor				*dupl_cur(t_cursor *cur, int addr);
void					add_cur(t_cursor **list, t_cursor *cur);

/*
** VM exec funcs
*/
void					parse_types_code(t_vm *vm, t_cursor *cursor, t_op *op);
uint8_t					is_arg_types_valid(t_cursor *cursor, t_op *op);
uint8_t					is_args_valid(t_cursor *cursor, t_vm *vm, t_op *op);
uint32_t				step_size(int8_t arg_type, t_op *op);
uint32_t				calc_step(t_cursor *cursor, t_op *op);
int						check_position(int position);
void					cycles_to_die_check(t_vm *vm);
void					fight(t_vm *vm);

/*
** Output funcs
*/
void					print_arena(t_vm *vm);
void					print_intro(t_vm *vm);
void					print_winner(t_vm *vm);
void					vs_map(t_cursor *cursor);

int ft_getopts(char **av, int ac, int *i);
#endif
