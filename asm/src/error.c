#include "asm.h"
#include "error.h"

void	lexical_error(char *token, unsigned row)
{
	printf("[ERROR] Lexical error: couldn't parse token \"%s\" (row %u)", token, row);
	exit (1);
}

void	token_error(char *token, unsigned row)
{
	printf("[ERROR] Unexpected token \"%s\" (row %u)", token, row);
	exit (1);
}

void	argument_error(char *arg, unsigned row)
{
	printf("[ERROR] Invalid argument \"%s\" (row %u)", arg, row);
	exit (1);
}

void	operator_error(char *token, unsigned row)
{
	printf("[ERROR] Unexpected operator \"%s\" (row %u)", token, row);
	exit (1);
}

void	error_exit(char *error) {
	ft_printf("%s", error);
	exit (1);	
}