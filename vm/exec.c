#include "corewar.h"

int		get_dir_size(int op_code)
{
	if ((op_code >= 0 && op_code <= 7) 
	|| op_code == 12 
	|| op_code == 16)
		return (4);
	else
		return (2);
}

int find_addr(int addr)
{
    addr %= MEM_SIZE;
    if (addr < 0)
        addr += MEM_SIZE;
    return (addr);
}

int		bytecode_to_int_op(uint8_t *arena, int addr, int size)
{
	int			result;
	int			sign;
	int			i;

	result = 0;
	sign = (int)(arena[find_addr(addr)] & 0x80);
	i = 0;
	while (size)
	{
		if (sign)
			result += ((arena[find_addr(addr + size - 1)] ^ 0xFF) << (i++ * 8));
		else
			result += arena[find_addr(addr + size - 1)] << (i++ * 8);
		size--;
	}
	if (sign)
		result = ~(result);
	return (result);
}

void		int_to_bytecode(uint8_t *arena, int addr, int value,
						int size)
{
	int i;

	i = 0;
	while (size)
	{
		arena[find_addr(addr + size - 1)] = (int)((value >> i) & 0xFF);
		i += 8;
		size--;
	}
}

int get_byte(int addr, t_vm *vm)
{
    return (vm->arena[find_addr(addr)]);
}

int	step_size(uint8_t arg_type, int dir_size)
{
	if (arg_type & T_REG)
		return (REG_LEN);
	else if (arg_type & T_DIR)
		return (dir_size);
	else if (arg_type & T_IND)
		return (IND_SIZE);
	return (0);
}

int		get_arg(t_vm *vm, t_cursor *cursor, int index, int mod)
{
	int		dir_size;
	int		value;
	int		addr;

	dir_size = get_dir_size(cursor->op_code);
	value = 0;
	if (cursor->args_types[index - 1] & T_REG)
		value = cursor->reg[get_byte(cursor->pos + cursor->step, vm)];
	else if (cursor->args_types[index - 1] & T_DIR)
		value = bytecode_to_int_op(vm->arena,
								cursor->pos + cursor->step,
								dir_size);
	else if (cursor->args_types[index - 1] & T_IND)
	{
		addr = bytecode_to_int_op(vm->arena,
								cursor->pos + cursor->step,
								IND_SIZE);
		value = bytecode_to_int_op(vm->arena,
							cursor->pos + (mod ? (addr % IDX_MOD) : addr),
							DIR_SIZE);
	}
	cursor->step += step_size(cursor->args_types[index - 1], dir_size);
	return (value);
}