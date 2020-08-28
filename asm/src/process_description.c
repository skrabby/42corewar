/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_description.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrabby <skrabby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 12:18:31 by skrabby           #+#    #+#             */
/*   Updated: 2020/08/22 17:22:34 by skrabby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "error.h"
#include "config.h"

static void	process_name(t_parser *parser, t_token **cur)
{
	(*cur) = (*cur)->next;
	if (!(*cur) || (*cur)->type != STRING)
		error_exit("Name expected");
	if (!(parser->name = ft_strsub((*cur)->content,
		1, ft_strlen((*cur)->content) - 2)))
		error_exit(MALLOC_ERR);
	if (ft_strlen(parser->name) > NAME_LENGTH)
		error_exit("Name length error");
}

static void	process_comment(t_parser *parser, t_token **cur)
{
	(*cur) = (*cur)->next;
	if (!(*cur) || (*cur)->type != STRING)
		error_exit("Comment expected");
	if (!(parser->comment = ft_strsub((*cur)->content,
		1, ft_strlen((*cur)->content) - 2)))
		error_exit(MALLOC_ERR);
	if (ft_strlen(parser->name) > COMMENT_LENGTH)
		error_exit("Comment length error");
}

void		process_description(t_parser *parser, t_token **cur)
{
	while ((!parser->name || !parser->comment) && (*cur))
	{
		if ((*cur)->content)
		{
			if (!parser->name && !ft_strcmp((*cur)->content, NAME_CMD_STRING))
				process_name(parser, cur);
			else if (!parser->comment &&
				!ft_strcmp((*cur)->content, COMMENT_CMD_STRING))
				process_comment(parser, cur);
		}
		(*cur) = (*cur)->next;
	}
}
