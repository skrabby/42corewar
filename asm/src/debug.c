#include "asm.h"
#include "error.h"
#include "config.h"
#include "op.h"

void	debug_description(t_parser *parser)
{
	if (DEBUG_MODE)
	{
		printf("[COREWAR MAGIC HEX]: \033[0;32m%-#30X\033[0m\n", COREWAR_EXEC_MAGIC);
		printf("[BYTE POSITION]: \033[0;35m%-30d\033[0m\n\n", 0);
		printf("[CHAMP NAME]: \033[0;32m%-30s\033[0m\n", parser->name);
		printf("[CHAMP NAME MAXSIZE]: \033[0;36m%-128d\033[0m\n", NAME_LENGTH);
		printf("[BYTE POSITION]: \033[0;35m%-30d\033[0m\n\n", 4);
		printf("[DELIMITER]: \033[0;35m4\033[0m\n\n");
		printf("[CHAMP BODY SIZE]: \033[0;36m%d\033[0m\n", parser->pos);
		printf("[CHAMP BODY SIZE IN BYTECODE]: \033[0;35m4\033[0m\n");
		printf("[BYTE POSITION]: \033[0;35m%-30d\033[0m\n\n", 4 + NAME_LENGTH + 4);
		printf("[CHAMP COMMENT]: \033[0;32m%s\033[0m\n", parser->comment);
		printf("[CHAMP COMMENT MAXSIZE]: \033[0;36m%-30d\033[0m\n", COMMENT_LENGTH);
		printf("[BYTE POSITION]: \033[0;35m%-30d\033[0m\n\n", 4 + NAME_LENGTH + 4 + 4);
		printf("[DELIMITER]: \033[0;35m4\033[0m\n\n");
		printf("[CHAMP BODY]\n\n");
	}
}

void	debug(t_parser *parser)
{
	if (DEBUG_MODE)
	{
		t_token *token;

		token = parser->tokens;
		debug_description(parser);
		while (token)
		{
			if (token->type != NEW_LINE && token->type != SEPARATOR &&
				token->type != COMMAND && token->type != STRING)
			{
				printf("[TOKEN CONTENT]: \033[0;32m%-30s\033[0m", token->content);
				printf("[TOKEN TYPE]: \033[0;36m%-30s\033[0m", g_type[token->type]);
				printf("[BYTE POSITION]: \033[0;35m%-30d\033[0m\n", 12 + NAME_LENGTH + COMMENT_LENGTH + 4 + token->pos);
			}
			token = token->next;
		}
	}
}