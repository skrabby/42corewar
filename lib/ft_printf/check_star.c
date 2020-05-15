/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_star.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 22:55:57 by oelaina           #+#    #+#             */
/*   Updated: 2019/11/02 18:23:09 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_star_for_first(const char ***s, t_flags *flags, va_list arg)
{
	if (***s == '*')
	{
		while (***s == '*')
			(**s)++;
		(**s)--;
		flags->first_num = va_arg(arg, int);
		if (flags->first_num < 0)
		{
			flags->first_num = flags->first_num * -1;
			flags->is_minus = 1;
		}
		if (ft_isdigit(*(**s + 1)))
		{
			(**s)++;
			flags->first_num = ft_atoi(**s);
		}
	}
	else
		flags->first_num = ft_atoi(**s);
}

void	check_star_for_second(const char **s, t_flags *flags, va_list arg)
{
	if (**s == '*')
	{
		while (**s == '*')
			(*s)++;
		(*s)--;
		flags->second_num = va_arg(arg, int);
		if (flags->second_num < 0)
			flags->is_secondnum = 0;
		if (ft_isdigit(**s + 1))
		{
			(*s)++;
			flags->first_num = ft_atoi(*s);
		}
	}
	else
		flags->second_num = ft_atoi(*s);
}
