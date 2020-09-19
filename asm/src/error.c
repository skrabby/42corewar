/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrabby <skrabby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 12:18:03 by skrabby           #+#    #+#             */
/*   Updated: 2020/09/19 14:57:34 by skrabby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "error.h"

void	lexical_error(char *token, unsigned row)
{
	ft_printf("\033[1;31m[ERROR]\033[0m Lexical error:\
	couldn't parse token \"%s\" (row %u)\n", token, row);
	exit(1);
}

void	label_error(char *label, t_mention *mentions)
{
	ft_printf("\033[1;31m[ERROR]\033[0m Undeclared label \"%s\" (row ", label);
	while (mentions)
	{
		ft_printf("%u", mentions->row);
		mentions = mentions->next;
		if (mentions != NULL)
			ft_printf(", ");
	}
	ft_printf(")\n");
	exit(1);
}

void	token_error(char *token, unsigned row)
{
	ft_printf("\033[1;31m[ERROR]\033[0m\
	Unexpected token \"%s\" (row %u)\n", token, row);
	exit(1);
}

void	argument_error(char *arg, unsigned row)
{
	ft_printf("\033[1;31m[ERROR]\033[0m\
	Invalid argument \"%s\" (row %u)\n", arg, row);
	exit(1);
}

void	operator_error(char *token, unsigned row)
{
	ft_printf("\033[1;31m[ERROR]\033[0m\
	Unexpected operator \"%s\" (row %u)\n", token, row);
	exit(1);
}
