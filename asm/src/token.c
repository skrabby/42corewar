/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrabby <skrabby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 12:18:42 by skrabby           #+#    #+#             */
/*   Updated: 2020/08/22 17:23:25 by skrabby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "error.h"

void	add_token_last(t_token **list, t_token *new)
{
	t_token	*current;

	if (list)
	{
		if (*list)
		{
			current = *list;
			while (current->next)
				current = current->next;
			if (current->type == NEW_LINE && new->type == NEW_LINE)
				ft_memdel((void **)&new);
			else
				current->next = new;
		}
		else
		{
			if (new->type == NEW_LINE)
				ft_memdel((void **)&new);
			else
				*list = new;
		}
	}
}

t_token	*init_token(char *content, unsigned row, t_type type)
{
	t_token *token;

	if (!(token = (t_token*)ft_memalloc(sizeof(t_token))))
		error_exit(MALLOC_ERR);
	token->row = row;
	token->type = type;
	token->content = content;
	token->next = NULL;
	token->pos = -1;
	return (token);
}
