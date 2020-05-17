#include "asm.h"
#include "error.h"

t_token	*init_token()
{
	t_token *token;

	if (!(token = (t_token*)ft_memalloc(sizeof(t_token))))
		error_exit(MALLOC_ERR);
	return (token);
}