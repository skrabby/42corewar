#include "asm.h"
#include "error.h"
#include "utils.h"
#include "config.h"

int		parse_str(char *line)
{
	int i;
	
	i = 1;
	while (line[i] != '\"' && line[i] != '\0')
		i++;
	if (line[i] == '\"')
		i++;
	ft_printf("token: %s\n", ft_strndup(line, i));
	return (i);
}

int		parse_token(char *line)
{
	int i;
	int begin;

	i = 0;
	begin = 0;
	if (line[i] == COMMENT_CHAR || line[i] == '\0')
		return (-1);
	else if (line[i] == '\"')
		return(parse_str(line));
	else if (is_delimiter(line[i])) {
		if (line[i] == SEPARATOR_CHAR) 
			return (1);
		i++;
	}
	while(!is_delimiter(line[i]))
		i++;
	ft_printf("token: %s\n", ft_strndup(line + begin, i));
	return (i);
}

void	parse_tokens(char *line)
{
	int i;
	int res;

	i = 0;
	while(line[i] != '\0')
	{
		while(is_whitespace(line[i]))
			i++;
		res = parse_token(line + i);
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
		if (line)
			parse_tokens(line);
		free(line);
	}
	if (read == -1)
		error_exit(READ_FILE_ERR);
}