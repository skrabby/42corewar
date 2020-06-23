#include "asm.h"
#include "error.h"
#include "config.h"

void	process_body(t_parser *parser, t_token **cur)
{
	while ((*cur)) {
		(*cur) = (*cur)->next;
	}
}