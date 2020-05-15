/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_create_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 22:26:15 by oelaina           #+#    #+#             */
/*   Updated: 2019/11/02 18:23:11 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	clear_f_a(t_flags *flags, t_args *args)
{
	if (flags->type != 'c')
		free(args->str);
	free(flags);
	free(args);
}

void	create_var(t_flags **flags, t_args **args, char **print)
{
	*print = ft_strnew(0);
	*flags = create_struct_of_flags();
	*args = create_struct_of_args();
}

void	clear_and_create_var(t_flags **flags, t_args **args)
{
	clear_f_a(*flags, *args);
	*flags = create_struct_of_flags();
	*args = create_struct_of_args();
}

void	read_symb(const char *s, t_args *args, va_list arg)
{
	if (*s == 'c')
		args->symb = va_arg(arg, int);
}
