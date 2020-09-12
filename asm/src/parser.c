/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrabby <skrabby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 12:18:12 by skrabby           #+#    #+#             */
/*   Updated: 2020/09/12 16:41:18 by skrabby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "error.h"
#include "utils.h"
#include "config.h"

int		parse_token(t_parser *parser, char *line)
{
	int		i;
	char	*content;
	t_type	type;

	i = 0;
	if (line[i] == '\"' || parser->str_parse)
		return (parse_str(parser, line));
	else if (line[i] == COMMENT_CHAR || line[i] == '\0')
		return (-1);
	else if (is_delimiter(line[i]))
	{
		if (line[i] == SEPARATOR_CHAR)
		{
			add_token_last(&parser->tokens,
			init_token(NULL, parser->row, SEPARATOR));
			return (1);
		}
	}
	i++;
	while (!is_delimiter(line[i]))
		i++;
	content = ft_strndup(line, i);
	type = define_type(content, parser->row);
	add_token_last(&parser->tokens, init_token(content, parser->row, type));
	return (i);
}

void	parse_tokens(t_parser *parser, char *line)
{
	int i;
	int res;

	i = 0;
	while (line[i] != '\0')
	{
		while (is_whitespace(line[i]))
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

	while ((read = get_next_line(parser->fd, &line)))
	{
		parser->row += 1;
		if (line)
		{
			parse_tokens(parser, line);
			add_token_last(&parser->tokens,
			init_token(NULL, parser->row, NEW_LINE));
		}
		free(line);
	}
	if (read == -1)
		error_exit(READ_FILE_ERR);
}
