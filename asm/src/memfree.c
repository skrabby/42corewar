/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memfree.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrabby <skrabby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 16:56:35 by skrabby           #+#    #+#             */
/*   Updated: 2020/09/12 17:12:58 by skrabby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		free_tokens(t_token *tokens)
{
	t_token *token;

	while (tokens)
	{
		token = tokens;
		tokens = tokens->next;
		ft_memdel((void **)&token->content);
		ft_memdel((void **)&token);
	}
}

static void		free_mentions(t_mention *mentions)
{
	t_mention *mention;

	mention = mentions;
	while (mentions)
	{
		mention = mentions;
		mentions = mentions->next;
		ft_memdel((void **)&mention);
	}
}

static void		free_labels(t_label *labels)
{
	t_label *label;

	label = labels;
	while (labels)
	{
		label = labels;
		labels = labels->next;
		free_mentions(label->mentions);
		ft_memdel((void **)&label->name);
		ft_memdel((void **)&label);
	}
}

void			free_helper(t_parser *parser)
{
	free_tokens(parser->tokens);
	free_labels(parser->labels);
	ft_memdel((void **)&parser->name);
	ft_memdel((void **)&parser->comment);
	ft_memdel((void **)&parser->body);
	ft_memdel((void **)&parser);
}
