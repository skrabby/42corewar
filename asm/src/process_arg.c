/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrabby <skrabby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 12:18:20 by skrabby           #+#    #+#             */
/*   Updated: 2020/08/22 17:07:32 by skrabby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "error.h"
#include "op.h"

static int8_t	get_arg_type(t_type type)
{
	if (type == DIRECT || type == DIRECT_LABEL)
		return (T_DIR);
	else if (type == INDIRECT || type == INDIRECT_LABEL)
		return (T_IND);
	else if (type == REGISTER)
		return (T_REG);
	else
		return (0);
}

static void		process_mention(t_parser *parser, t_token *cur, t_op *op)
{
	t_label		*label;
	char		*name;
	unsigned	start;
	size_t		size;

	start = (cur->type == DIRECT_LABEL) ? 2 : 1;
	size = (cur->type == DIRECT_LABEL) ? op->t_dir_size : IND_SIZE;
	if (!(name = ft_strsub(cur->content,
				start, ft_strlen(cur->content) - start)))
		error_exit(MALLOC_ERR);
	if (!(label = find_label(parser->labels, name)))
	{
		label = init_label(name, -1);
		add_label(&(parser->labels), label);
	}
	ft_strdel(&name);
	add_mention(&label->mentions, init_mention(parser, cur, size));
	parser->pos += size;
}

static void		process_num(t_parser *parser, t_token *cur, t_op *op)
{
	unsigned	start;
	size_t		size;

	start = (cur->type == DIRECT) ? 1 : 0;
	size = (cur->type == DIRECT) ? op->t_dir_size : IND_SIZE;
	if (size == 2)
		int32_to_bytecode(parser->body, parser->pos,
						(int16_t)ft_atoi32(&cur->content[start]), size);
	else
		int32_to_bytecode(parser->body, parser->pos,
						ft_atoi32(&cur->content[start]), size);
	parser->pos += size;
}

static void		process_register(t_parser *parser, t_token *cur)
{
	int32_to_bytecode(parser->body, parser->pos,
					(int8_t)ft_atoi(&cur->content[1]), 1);
	parser->pos += 1;
}

int8_t			process_arg(t_parser *parser, t_token **cur,
							t_op *op, int arg_num)
{
	int8_t	type;

	type = get_arg_type((*cur)->type);
	if (!(op->args_types[arg_num] & type))
		argument_error(op->name, (*cur)->row);
	if ((*cur)->type == INDIRECT_LABEL
		|| (*cur)->type == DIRECT_LABEL)
		process_mention(parser, *cur, op);
	else if ((*cur)->type == INDIRECT
		|| (*cur)->type == DIRECT)
		process_num(parser, *cur, op);
	else
		process_register(parser, *cur);
	return (type);
}
