#include "corewar.h"

int32_t		bytecode_to_int32(const uint8_t *arena, int32_t addr, int32_t size)
{
	int32_t		result;
	int		sign;
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

int get_byte(int addr, t_vm *vm)
{
    return (vm->arena[find_addr(addr)]);
}

int find_addr(int addr)
{
    addr %= MEM_SIZE;
    if (addr < 0)
        addr += MEM_SIZE;
    return (addr);
}

int32_t		get_op_arg(t_vm *vm, t_cursor *cursor, int index, int mod)
{
	t_op		*op;
	int32_t		value;
	int32_t		addr;

	op = &g_op[cursor->op_code)]; //?
	value = 0;
	if (cursor->args_types[index - 1] & T_REG)
		value = cursor->reg[get_byte(vm, cursor->pc, cursor->step))];
	else if (cursor->args_types[index] & T_DIR)
		value = bytecode_to_int32(vm->arena,
								cursor->pc + cursor->step,
								op->t_dir_size);
	else if (cursor->args_types[index - 1] & T_IND)
	{
		addr = bytecode_to_int32(vm->arena,
								cursor->pc + cursor->step,
								IND_SIZE);
		value = bytecode_to_int32(vm->arena,
							cursor->pc + (mod ? (addr % IDX_MOD) : addr),
							DIR_SIZE);
	}
	cursor->step += step_size(cursor->args_types[index - 1], op); //?
	return (value);
}