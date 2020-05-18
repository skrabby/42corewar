#include "asm.h"
#include "error.h"
#include "utils.h"
#include "config.h"

int		parse_str(t_parser *parser, char *line)
{
	int i;
	static char *s;

	if (!s)
		s = "";
	i = line[0] == '\"' ? 1 : 0;
	while (line[i] != '\"' && line[i] != '\0')
		i++;
	if (line[i] == '\"')
	{
		i++;
		s = ft_strlen(s) == 0 ? ft_strndup(line, i) : strjoin_free(1, 1, s, ft_strndup(line, i));
		add_token_last(&parser->tokens, init_token(s, parser->row, STRING));
		s = "";
		parser->str_parse = 0;
		return (i); 
	}
	s = ft_strlen(s) == 0 ? ft_strndup(line, i) : strjoin_free(1, 1, s, ft_strndup(line, i));
	s[ft_strlen(s) - 1] = '\n';
	parser->str_parse = 1;
	return (-1);
}

t_type	define_type(char c, char c2)
{
	if (c == COMMAND_CHAR)
		return (COMMAND);
	else if (c == DIRECT_CHAR)
		return (c2 == LABEL_CHAR ? DIRECT_LABEL : DIRECT);
	else if (c == LABEL_CHAR)
		return (INDIRECT_LABEL);
	else
		return (INDIRECT);
}

int		parse_token(t_parser *parser, char *line)
{
	int		i;
	int		begin;
	t_type	type;

	i = 0;
	begin = 0;
	if (line[i] == '\"' || parser->str_parse)
		return(parse_str(parser, line));
	else if (line[i] == COMMENT_CHAR || line[i] == '\0')
		return (-1);
	else if (is_delimiter(line[i])) {
		if (line[i] == SEPARATOR_CHAR) 
			return (1);
	}
	type = define_type(line[i], line[i + 1]);
	i++;
	while(!is_delimiter(line[i]))
		i++;
	add_token_last(&parser->tokens, init_token(ft_strndup(line + begin, i), parser->row, type));
	return (i);
}

void	parse_tokens(t_parser *parser, char *line)
{
	int i;
	int res;

	i = 0;
	while(line[i] != '\0')
	{
		while(is_whitespace(line[i]))
			i++;
		res = parse_token(parser, line + i);
		if (res == -1)
			break ;
		i += res;
	} 
}

void	parse(t_parser *parser)
{
	char	*line;
	int		read;
	while (read = get_next_line(parser->fd, &line))
	{
		parser->row += 1;
		if (line)
			parse_tokens(parser, line);
		free(line);
	}
	if (read == -1)
		error_exit(READ_FILE_ERR);
}