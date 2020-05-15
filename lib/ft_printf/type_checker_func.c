/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_checker_func.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 13:17:31 by oelaina           #+#    #+#             */
/*   Updated: 2019/11/02 18:23:53 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*check_last_let_for_l(char *str, va_list arg, t_flags *flags)
{
	int flag;

	flag = 0;
	if (*str == 'L')
		flags->is_longfloat = 1;
	str++;
	if (char_checker("l", *str))
		flag = 1;
	while (!(char_checker("diuoxUXfFbeg", *str)))
		str++;
	flags->type = *str;
	if (*str == 'b')
		return (ft_itoa_base_small_lu(va_arg(arg, unsigned long long), 2));
	else
		return (return_result_for_l(str, arg, flags, flag));
}

char	*check_last_let_for_p(char *str, va_list arg, t_flags *flags)
{
	flags->type = 'p';
	flags->is_grid = 1;
	while (char_checker("p", *str))
		str++;
	return ((ft_itoa_base_small_lu(va_arg(arg, unsigned long), 16)));
}

char	*check_last_let_for_z(char *str, va_list arg, t_flags *flags)
{
	while (char_checker("diuoxUXFbeg", *str))
		str++;
	flags->type = *str;
	if (*str == 'd' || *str == 'i' || *str == 'z')
		return (ft_itoa_base_ll(va_arg(arg, size_t), 10));
	else if (*str == 'u' || *str == 'U')
		return (ft_itoa_base_lu(va_arg(arg, size_t), 10));
	else if (*str == 'o')
		return (ft_itoa_base_lu(va_arg(arg, size_t), 8));
	else if (*str == 'b')
		return (ft_itoa_base_lu(va_arg(arg, size_t), 2));
	else if (*str == 'x')
		return (ft_itoa_base_small_lu(va_arg(arg, size_t), 16));
	else if (*str == 'X')
		return (ft_itoa_base_lu(va_arg(arg, size_t), 16));
	return ("");
}

char	*check_last_let_for_h(char *str, va_list arg, t_flags *flags)
{
	int flag;

	flag = 0;
	str++;
	if (char_checker("h", *str))
		flag = 1;
	while (!(char_checker("diuoxfFXbUeg", *str)))
	{
		if (!*str)
			return ("");
		str++;
	}
	flags->type = *str;
	if (*str == 'b')
		return (ft_itoa_base_small_lu(va_arg(arg, unsigned long long), 2));
	else
		return (return_result_for_h(str, arg, flags, flag));
}

char	*check_last_let_for_dioux(char *str,
va_list arg, t_flags *flags)
{
	flags->type = *str;
	if (*str == 'd' || *str == 'i')
		return (ft_itoa_base_ll(va_arg(arg, int), 10));
	else if (*str == 'u' || *str == 'U')
	{
		flags->is_plus = 0;
		flags->is_space = 0;
		return (ft_itoa_base_lu(va_arg(arg, unsigned int), 10));
	}
	else if (*str == 'o')
		return (ft_itoa_base_lu(va_arg(arg, unsigned int), 8));
	else if (*str == 'x')
		return (ft_itoa_base_small_lu(va_arg(arg, unsigned int), 16));
	else if (*str == 'X')
		return (ft_itoa_base_lu(va_arg(arg, unsigned int), 16));
	else if (*str == 'b')
	{
		flags->is_plus = 0;
		return (ft_itoa_base_lu(va_arg(arg, unsigned int), 2));
	}
	else if (*str == 'f' || *str == 'F' || *str == 'e' || *str == 'g')
		return (handle_float((long double)va_arg(arg, double), flags));
	return ("");
}
