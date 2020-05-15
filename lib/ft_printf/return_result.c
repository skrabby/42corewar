/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_result.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:39:03 by oelaina           #+#    #+#             */
/*   Updated: 2019/11/02 18:23:49 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*return_result_for_l(char *s, va_list arg,
t_flags *flags, int flag)
{
	if ((*s == 'd' || *s == 'i') && flag == 1)
		return (ft_itoa_base_ll(va_arg(arg, long long), 10));
	else if ((*s == 'u' || *s == 'U') && flag == 1)
		return (ft_itoa_base_lu(va_arg(arg, unsigned long long), 10));
	else if (*s == 'o' && flag == 1)
		return (ft_itoa_base_lu(va_arg(arg, unsigned long long), 8));
	else if (*s == 'x' && flag == 1)
		return (ft_itoa_base_small_lu(va_arg(arg, unsigned long long), 16));
	else if (*s == 'X' && flag == 1)
		return (ft_itoa_base_lu(va_arg(arg, unsigned long long), 16));
	else if ((*s == 'd' || *s == 'i') && flag == 0)
		return (ft_itoa_base_ll(va_arg(arg, long), 10));
	else if ((*s == 'u' || *s == 'U') && flag == 0)
		return (ft_itoa_base_lu(va_arg(arg, unsigned long), 10));
	else if (*s == 'o' && flag == 0)
		return (ft_itoa_base_lu(va_arg(arg, unsigned long), 8));
	else if (*s == 'x' && flag == 0)
		return (ft_itoa_base_small_lu(va_arg(arg, unsigned long), 16));
	else if (*s == 'X' && flag == 0)
		return (ft_itoa_base_lu(va_arg(arg, unsigned long), 16));
	else if (char_checker("fFeg", *s) && flags->is_longfloat == 1)
		return (handle_float(va_arg(arg, long double), flags));
	else if (char_checker("Ffeg", *s) && flags->is_longfloat == 0)
		return (handle_float((long double)va_arg(arg, double), flags));
	return ("");
}

char	*return_result_for_h(char *str,
va_list arg, t_flags *flags, int flag)
{
	if ((*str == 'd' || *str == 'i') && flag == 0)
		return (ft_itoa_base_ll((short int)va_arg(arg, int), 10));
	else if ((*str == 'd' || *str == 'i') && flag == 1)
		return (ft_itoa_base_ll((signed char)va_arg(arg, int), 10));
	else if ((*str == 'u' || *str == 'U') && flag == 0)
		return (ft_itoa_base_lu((unsigned short int)va_arg(arg, int), 10));
	else if ((*str == 'u' || *str == 'U') && flag == 1)
		return (ft_itoa_base_lu((unsigned char)va_arg(arg, int), 10));
	else if (*str == 'o' && flag == 0)
		return (ft_itoa_base_lu((unsigned short int)va_arg(arg, int), 8));
	else if (*str == 'o' && flag == 1)
		return (ft_itoa_base_lu((unsigned char)va_arg(arg, int), 8));
	else if (*str == 'x' && flag == 0)
		return (ft_itoa_base_small_lu(
			(unsigned short int)va_arg(arg, int), 16));
	else if (*str == 'x' && flag == 1)
		return (ft_itoa_base_small_lu((unsigned char)va_arg(arg, int), 16));
	else if (*str == 'X' && flag == 0)
		return (ft_itoa_base_lu((unsigned short int)va_arg(arg, int), 16));
	else if (*str == 'X' && flag == 1)
		return (ft_itoa_base_lu((unsigned char)va_arg(arg, int), 16));
	else if (char_checker("Ffeg", *str))
		return (handle_float((long double)va_arg(arg, double), flags));
	return ("");
}

void	get_final_char(char *s, va_list arg, t_flags *flags, t_args *args)
{
	if (char_checker("%", *s))
		final_percent('%', flags, args);
	else if (char_checker("p", *s))
		final_nbstr(check_last_let_for_p(s, arg, flags), flags, args);
	else if (char_checker("lLj", *s))
		final_nbstr(check_last_let_for_l(s, arg, flags), flags, args);
	else if (char_checker("z", *s))
		final_nbstr(check_last_let_for_z(s, arg, flags), flags, args);
	else if (char_checker("h", *s))
		final_nbstr(check_last_let_for_h(s, arg, flags), flags, args);
	else if (char_checker("diouXxbU", *s))
		final_nbstr(check_last_let_for_dioux(s, arg, flags), flags, args);
	else if (char_checker("s", *s))
		final_charstr(ft_strdup(va_arg(arg, char *)), flags, args);
	else if (char_checker("fFeg", *s))
	{
		flags->type = *s;
		final_nbstr(handle_float((long double)va_arg(arg, double), flags),
		flags, args);
	}
	else if (char_checker("r", *s))
		final_charstr(r_handler(va_arg(arg, char *)), flags, args);
}

void	return_result_for_c(int **countnull,
t_flags **flags, char **print, t_args **args)
{
	(*flags)->type = 'c';
	final_charsymb((*args)->symb, (*flags), (*args));
	if ((*args)->symb == '\0')
	{
		if ((*flags)->is_minus == 1)
		{
			ft_putstr(*print);
			ft_putchar('\0');
			free(*print);
			*print = ft_strdup("");
			(**countnull)++;
		}
		newstr(print, (*args)->str);
		**countnull += (int)ft_strlen(*print) + 1;
		ft_putstr(*print);
		if ((*flags)->is_minus == 0)
			ft_putchar('\0');
		free(*print);
		*print = ft_strnew(0);
	}
	else
		newstr(print, (*args)->str);
}
