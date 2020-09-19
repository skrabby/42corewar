/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_description.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 12:18:31 by skrabby           #+#    #+#             */
/*   Updated: 2020/09/19 20:33:05 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "error.h"
#include "config.h"

static void	process_name(t_parser *parser, t_token **cur)
{
	(*cur) = (*cur)->next;
	if (!(*cur) || (*cur)->type != STRING)
		error_exit(NAME_ERR);
	if (!(parser->name = ft_strsub((*cur)->content,
		1, ft_strlen((*cur)->content) - 2)))
		error_exit(MALLOC_ERR);
	if (ft_strlen(parser->name) > NAME_LENGTH)
		error_exit(NAME_LEN_ERR);
}

static void	process_comment(t_parser *parser, t_token **cur)
{
	(*cur) = (*cur)->next;
	if (!(*cur) || (*cur)->type != STRING)
		error_exit(COMMENT_ERR);
	if (!(parser->comment = ft_strsub((*cur)->content,
		1, ft_strlen((*cur)->content) - 2)))
		error_exit(MALLOC_ERR);
	if (ft_strlen(parser->comment) > COMMENT_LENGTH)
		error_exit(COMMENT_LEN_ERR);
}

void		process_description(t_parser *parser, t_token **cur)
{
	if (*cur == NULL)
		error_exit(EMPTY_FILE);
	while ((!parser->name || !parser->comment) && (*cur))
	{
		if ((*cur)->content)
		{
			if (!parser->name && !ft_strcmp((*cur)->content, NAME_CMD_STRING))
				process_name(parser, cur);
			else if (!parser->comment &&
				!ft_strcmp((*cur)->content, COMMENT_CMD_STRING))
				process_comment(parser, cur);
			else
				error_exit(COMMAND_ERR);
		}
		(*cur) = (*cur)->next;
	}
	if (!parser->name)
		error_exit(NAME_ERR);
	else if (!parser->comment)
		error_exit(COMMENT_ERR);
}
