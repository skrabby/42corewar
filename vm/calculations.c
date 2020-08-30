//
// Created by poligon on 08.08.2020.
//

#include "corewar.h"


uint32_t	step_size(int8_t arg_type, t_op *op)
{
	if (arg_type & T_REG)
		return (REG_LEN);
	else if (arg_type & T_DIR)
		return (op->t_dir_size);
	else if (arg_type & T_IND)
		return (IND_SIZE);
	return (0);
}

uint32_t	calc_step(t_cursor *cursor, t_op *op)
{
	int32_t		i;
	uint32_t	step;

	i = 0;
	step = 0;
	step += OP_CODE_LEN + (op->args_types_code ? ARGS_CODE_LEN : 0);
	while (i < g_op[cursor->op_code - 1].args_num)
	{
		step += step_size(cursor->args_types[i], op);
		i++;
	}
	return (step);
}