/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_body.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrabby <skrabby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 12:18:28 by skrabby           #+#    #+#             */
/*   Updated: 2020/08/22 17:08:13 by skrabby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "error.h"
#include "config.h"
#include "op.h"

static void		process_label(t_parser *parser, t_token **cur)
{
	t_label	*label;
	char	*name;

	if (!(name = ft_strsub((*cur)->content,
				0, ft_strlen((*cur)->content) - 1)))
		error_exit(MALLOC_ERR);
	if (!(label = find_label(parser->labels, name)))
		add_label(&(parser->labels), init_label(name, parser->op_pos));
	if (label && label->op_pos == -1)
		label->op_pos = parser->pos;
	(*cur)->pos = parser->pos;
	ft_strdel(&name);
}

static int8_t	process_args(t_parser *parser, t_token **cur, t_op *op)
{
	int		arg_num;
	int8_t	types_code;
	int8_t	type;

	arg_num = 0;
	types_code = 0;
	while (arg_num < op->args_num)
	{
		(*cur)->pos = parser->pos;
		if ((*cur)->type >= REGISTER && (*cur)->type <= INDIRECT_LABEL)
		{
			type = process_arg(parser, cur, op, arg_num);
			update_types_code(&types_code, type, arg_num);
			(*cur) = (*cur)->next;
		}
		else
			token_error((*cur)->content, (*cur)->row);
		if (arg_num++ != op->args_num - 1)
		{
			if ((*cur)->type != SEPARATOR)
				token_error((*cur)->content, (*cur)->row);
			(*cur) = (*cur)->next;
		}
	}
	return (types_code);
}

static void		process_operator(t_parser *parser, t_token **cur)
{
	t_op	*op;
	int8_t	types_code;

	if ((op = get_op((*cur)->content)))
	{
		(*cur)->pos = parser->pos;
		parser->body[parser->pos++] = op->code;
		(*cur) = (*cur)->next;
		if (op->args_types_code)
			parser->pos++;
		types_code = process_args(parser, cur, op);
		if (op->args_types_code)
			parser->body[parser->op_pos + 1] = types_code;
	}
	else
		operator_error((*cur)->content, (*cur)->row);
}

void			process_mentions(t_parser *parser)
{
	t_label		*label;
	t_mention	*mention;

	label = parser->labels;
	while (label)
	{
		if (label->op_pos == -1)
			label_error(label->name, label->mentions);
		else
		{
			mention = label->mentions;
			while (mention)
			{
				if (mention->size == 2)
					int32_to_bytecode(parser->body, mention->pos,
								(int16_t)(label->op_pos - mention->op_pos),
								mention->size);
				else
					int32_to_bytecode(parser->body, mention->pos,
						label->op_pos - mention->op_pos, mention->size);
				mention = mention->next;
			}
		}
		label = label->next;
	}
}

void			process_body(t_parser *parser, t_token **cur)
{
	while ((*cur))
	{
		if (parser->pos >= parser->body_size)
			adjust_code_buff(parser);
		parser->op_pos = parser->pos;
		if ((*cur)->type == LABEL)
		{
			process_label(parser, cur);
			(*cur) = (*cur)->next;
		}
		if ((*cur)->type == OPERATOR)
			process_operator(parser, cur);
		if ((*cur)->type == NEW_LINE)
		{
			(*cur) = (*cur)->next;
		}
		else
			token_error((*cur)->content, (*cur)->row);
	}
}
