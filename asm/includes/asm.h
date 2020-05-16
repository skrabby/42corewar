#ifndef ASM_H

# define ASM_H

# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct			s_command
{
	char				*command;
	unsigned int		row;
	struct s_command	*next;
}						t_command;

typedef struct			s_parser
{
	int					fd;
	unsigned int		row;
	t_command			*commands;
	char				*name;
	char				*comment;
}						t_parser;

#endif