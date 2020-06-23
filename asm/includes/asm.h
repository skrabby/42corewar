#ifndef ASM_H

# define ASM_H

# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef	enum			s_type
{
	COMMAND,
	STRING,
	LABEL,
	OPERATOR,
	REGISTER,
	DIRECT,
	DIRECT_LABEL,
	INDIRECT,
	INDIRECT_LABEL,
	SEPARATOR,
	NEW_LINE,
	END
}						t_type;

typedef struct			s_token
{
	char				*content;
	unsigned			row;
	t_type				type;
	struct s_token	*next;
}						t_token;

typedef struct			s_parser
{
	int					fd;
	int					str_parse;
	unsigned			row;
	int					pos;
	int					op_pos;
	int					body_size;
	t_token				*tokens;
	char				*name;
	char				*comment;
}						t_parser;

void					error_exit(char *error);
void					parse(t_parser *parser);
t_token					*init_token(char *content, unsigned row, t_type type);
void					add_token_last(t_token **list, t_token *new);
void    				process_description(t_parser *parser, t_token **cur);

#endif