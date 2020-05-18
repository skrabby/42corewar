#include "asm.h"
#include "error.h"

void	add_token_last(t_token **list, t_token *new)
{
	t_token	*cur;

	if (!list)
		return ;
	cur = *list;
	if (*list)
	{
		while (cur->next)
			cur = cur->next;
		cur->next = new;
	}
	else
		*list = new;
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
	return (token);
}