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
		s = ft_strlen(s) == 0 ? ft_strndup(line, i) : strjoin_free(true, true, s, ft_strndup(line, i));
		add_token_last(&parser->tokens, init_token(s, parser->row, STRING));
		s = "";
		parser->str_parse = false;
		return (i); 
	}
	s = ft_strlen(s) == 0 ? ft_strndup(line, i) : strjoin_free(true, true, s, ft_strndup(line, i));
	s[ft_strlen(s) - 1] = '\n';
	parser->str_parse = true;
	return (-1);
}

t_type	get_label(char *content, t_type type)
{
	if (content[ft_strlen(content) - 1] == LABEL_CHAR)
		return LABEL;
	else if (type == INDIRECT)
		return (is_register(content) ? REGISTER : OPERATOR);
	else
		return type;
}


t_type parse_nb(char *content, t_type type)
{
	int i;

	i = 0;
	if (content[i] == '-')
		i++;
	while (ft_isdigit(content[i]))
		i++;
	if (is_delimiter(content[i]))
		return (INDIRECT);
	else
		return (get_label(content, type));
}


t_type	lexical_check(char *content, unsigned row, t_type type)
{
	int i;

	i = 0;
	if (content[i] == COMMAND_CHAR && type == COMMAND ||
		content[i] == DIRECT_CHAR && (type == DIRECT || type == DIRECT_LABEL))
		i++;
	if (content[i] == '-' && (type == DIRECT || type == INDIRECT))
		i++;
	while (content[i] && ft_strchr(LABEL_CHARS, content[i]))
		i++;
	if (content[i] != '\0' && content[i] != LABEL_CHAR)
		lexical_error(content, row);
	return type;
}

t_type	define_type(char *content, unsigned row)
{
	if (!content)
		lexical_error("", row);
	if (content[0] == COMMAND_CHAR)
		return (lexical_check(content, row, COMMAND));
	else if (content[0] == DIRECT_CHAR)
		return (content[1] == LABEL_CHAR ? lexical_check(content, row, get_label(content, DIRECT_LABEL)):
		lexical_check(content, row, DIRECT));
	else if (content[0] == LABEL_CHAR)
		return (lexical_check(content, row, get_label(content, INDIRECT_LABEL)));
	else
		return (lexical_check(content, row, parse_nb(content, INDIRECT)));
}