#include "asm.h"
#include "error.h"
#include "config.h"
#include "op.h"

void			adjust_code_buff(t_parser *parser)
{
	parser->body_size += CHAMP_MAX_SIZE;
	if (!(parser->body = (char *)realloc(parser->body,
		((size_t)parser->body_size + MAX_STATEMENT_SIZE))))
		error_exit(MALLOC_ERR);
}

t_op			*get_op(char *name)
{
	unsigned	i;

	i = 0;
	while (i < (sizeof(g_op) / sizeof(t_op)))
	{
		if (!ft_strcmp(g_op[i].name, name))
			return (&g_op[i]);
		i++;
	}
	return (NULL);
}

static uint8_t	get_arg_code(int8_t type)
{
	if (type == T_DIR)
		return (DIR_CODE);
	else if (type == T_REG)
		return (REG_CODE);
	else
		return (IND_CODE);
}

void			update_types_code(int8_t *types_code, int8_t type, int arg_num)
{
	(*types_code) |= (get_arg_code(type) << 2 * (4 - arg_num - 1));
}

void	int32_to_bytecode(char *data,
							int32_t pos,
							int32_t value,
							size_t size)
{
	int8_t		i;

	i = 0;
	while (size)
	{
		data[pos + size - 1] = (uint8_t)((value >> i) & 0xFF);
		i += 8;
		size--;
	}
}
