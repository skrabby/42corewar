#include "asm.h"
#include "error.h"
#include "config.h"

void		write_bytes(int fd, t_parser *parser)
{
	int32_t	len;
	int32_t	pos;
	char	*bytecode;

	pos = 0;
	len = 4 + PROG_NAME_LENGTH + 4 + 4 + COMMENT_LENGTH + 4 + parser->pos;
	if (!(bytecode = ft_strnew((size_t)len)))
		error_exit(MALLOC_ERR);
	int32_to_bytecode(bytecode, pos, COREWAR_EXEC_MAGIC, 4);
	pos += 4;
	ft_memcpy(&bytecode[pos], parser->name, ft_strlen(parser->name));
	pos += PROG_NAME_LENGTH;
	pos += 4;
	int32_to_bytecode(bytecode, pos, parser->pos, 4);
	pos += 4;
	ft_memcpy(&bytecode[pos], parser->comment, ft_strlen(parser->comment));
	pos += COMMENT_LENGTH;
	pos += 4;
	ft_memcpy(&bytecode[pos], parser->body, (size_t)parser->pos);
	write(fd, bytecode, (size_t)len);
	free(bytecode);
}