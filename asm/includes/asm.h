#ifndef ASM_H

# define ASM_H

# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct			s_token
{
	char				*content;
	unsigned int		row;
	struct s_command	*next;
}						t_token;

typedef struct			s_parser
{
	int					fd;
	unsigned int		row;
	t_token				*tokens;
	char				*name;
	char				*comment;
}						t_parser;

void					error_exit(char *error);
void					parse(t_parser *parser);

#endif