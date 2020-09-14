/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrabby <skrabby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 12:18:08 by skrabby           #+#    #+#             */
/*   Updated: 2020/08/22 16:41:53 by skrabby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "error.h"

t_label		*init_label(char *name, int op_pos)
{
	t_label	*label;

	if (!(label = (t_label *)ft_memalloc(sizeof(t_label))))
		error_exit(MALLOC_ERR);
	if (!(label->name = ft_strdup(name)))
		error_exit(MALLOC_ERR);
	label->op_pos = op_pos;
	label->mentions = NULL;
	label->next = NULL;
	return (label);
}

void		add_label(t_label **list, t_label *new)
{
	t_label	*current;

	if (list)
	{
		if (*list)
		{
			current = *list;
			while (current->next)
				current = current->next;
			current->next = new;
		}
		else
			*list = new;
	}
}

t_label		*find_label(t_label *list, char *name)
{
	t_label	*label;

	label = list;
	while (label)
	{
		if (!ft_strcmp(label->name, name))
			return (label);
		label = label->next;
	}
	return (label);
}

t_mention	*init_mention(t_parser *parser, t_token *token, size_t size)
{
	t_mention	*mention;

	if (!(mention = (t_mention *)ft_memalloc(sizeof(t_mention))))
		error_exit(MALLOC_ERR);
	mention->row = token->row;
	mention->pos = parser->pos;
	mention->op_pos = parser->op_pos;
	mention->size = size;
	mention->next = NULL;
	return (mention);
}

void		add_mention(t_mention **list, t_mention *new)
{
	t_mention	*current;

	if (list)
	{
		if (*list)
		{
			current = *list;
			while (current->next)
				current = current->next;
			current->next = new;
		}
		else
			*list = new;
	}
}
