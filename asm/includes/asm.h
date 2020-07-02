#ifndef ASM_H

# define ASM_H

# include "libft.h"
# include "op.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

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
	NEW_LINE
}						t_type;

static char				*g_type[] = {
	"COMMAND",
	"STRING",
	"LABEL",
	"OPERATOR",
	"REGISTER",
	"DIRECT",
	"DIRECT_LABEL",
	"INDIRECT",
	"INDIRECT_LABEL",
	"SEPARATOR",
	"NEW_LINE"
};

typedef struct			s_token
{
	char				*content;	// content of token
	unsigned			row;		// row position
	t_type				type;		// token's type
	int32_t				pos;		// token position in bytes
	struct s_token		*next;		// pointer to a next token
}						t_token;

typedef struct			s_mention
{
	unsigned			row;
	int32_t				pos;
	int32_t				op_pos;
	size_t				size;
	struct s_mention	*next;
}						t_mention;


typedef struct			s_label
{
	char				*name;
	int32_t				op_pos;
	t_mention			*mentions;
	struct s_label		*next;
}						t_label;

typedef struct			s_parser
{
	int					fd;			// file descriptor
	bool				str_parse;	// whether currently is the string parsing process
	unsigned			row;		// current row
	int32_t				pos;		// current parser byte position
	int32_t				op_pos;		// latest op start byte position
	int32_t				body_size;  // size of champions code in bytes
	t_token				*tokens;	// list of tokens
	t_label				*labels;	// list of labels
	char				*name;		// file name
	char				*comment;	// file comment
	char				*body;		// champions code body
}						t_parser;


void					error_exit(char *error);
void					parse(t_parser *parser);
int						parse_str(t_parser *parser, char *line);
t_type					get_label(char *content, t_type type);
t_type					parse_nb(char *content, t_type type);
t_type					lexical_check(char *content, unsigned row, t_type type);
t_type					define_type(char *content, unsigned row);
t_token					*init_token(char *content, unsigned row, t_type type);
void					add_token_last(t_token **list, t_token *new);
void    				process_description(t_parser *parser, t_token **cur);
void					process_body(t_parser *parser, t_token **cur);
void					adjust_code_buff(t_parser *parser);
int8_t					process_arg(t_parser *parser, t_token **current,
									t_op *op, int arg_num);
void					update_types_code(int8_t *types_code, int8_t type, int arg_num);
t_op					*get_op(char *name);
t_label					*init_label(char *name, int op_pos);
void					add_label(t_label **list, t_label *new);
t_label					*find_label(t_label *list, char *name);
t_mention				*init_mention(t_parser *parser, t_token *token, size_t size);
void					add_mention(t_mention **list, t_mention *new);
void					int32_to_bytecode(char *data, int32_t pos,
											int32_t value, size_t size);
void					process_mentions(t_parser *parser);
void					write_bytes(int fd, t_parser *parser);
void					debug(t_parser *parser);
											
#endif