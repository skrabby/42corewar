/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrabby <skrabby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 12:17:58 by skrabby           #+#    #+#             */
/*   Updated: 2020/08/22 16:47:22 by skrabby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "error.h"
#include "config.h"
#include "op.h"

void	debug_description(t_parser *parser)
{
	if (DEBUG_MODE)
	{
		ft_printf("[COREWAR MAGIC HEX]: \033[0;32m%-#30X\033[0m\n",
					COREWAR_EXEC_MAGIC);
		ft_printf("[BYTE POSITION]: \033[0;35m%-30d\033[0m\n\n", 0);
		ft_printf("[CHAMP NAME]: \033[0;32m%-30s\033[0m\n", parser->name);
		ft_printf("[CHAMP NAME MAXSIZE]: \033[0;36m%-128d\033[0m\n",
					NAME_LENGTH);
		ft_printf("[BYTE POSITION]: \033[0;35m%-30d\033[0m\n\n", 4);
		ft_printf("[DELIMITER]: \033[0;35m4\033[0m\n\n");
		ft_printf("[CHAMP BODY SIZE]: \033[0;36m%d\033[0m\n", parser->pos);
		ft_printf("[CHAMP BODY SIZE IN BYTECODE]: \033[0;35m4\033[0m\n");
		ft_printf("[BYTE POSITION]: \033[0;35m%-30d\033[0m\n\n",
					4 + NAME_LENGTH + 4);
		ft_printf("[CHAMP COMMENT]: \033[0;32m%s\033[0m\n", parser->comment);
		ft_printf("[CHAMP COMMENT MAXSIZE]: \033[0;36m%-30d\033[0m\n",
					COMMENT_LENGTH);
		ft_printf("[BYTE POSITION]: \033[0;35m%-30d\033[0m\n\n",
					4 + NAME_LENGTH + 4 + 4);
		ft_printf("[DELIMITER]: \033[0;35m4\033[0m\n\n");
		ft_printf("[CHAMP BODY]\n\n");
	}
}

void	debug(t_parser *parser)
{
	t_token *token;

	if (DEBUG_MODE)
	{
		token = parser->tokens;
		debug_description(parser);
		while (token)
		{
			if (token->type != NEW_LINE && token->type != SEPARATOR &&
				token->type != COMMAND && token->type != STRING)
			{
				ft_printf("[TOKEN CONTENT]: \033[0;32m%-30s\033[0m",
							token->content);
				ft_printf("[TOKEN TYPE]: \033[0;36m%-30s\033[0m",
							g_type[token->type]);
				ft_printf("[BYTE POSITION]: \033[0;35m%-30d\033[0m\n",
				12 + NAME_LENGTH + COMMENT_LENGTH + 4 + token->pos);
			}
			token = token->next;
		}
	}
}
