/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 21:49:25 by oelaina           #+#    #+#             */
/*   Updated: 2019/11/02 18:23:19 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags		*create_struct_of_flags(void)
{
	t_flags	*flag;

	if (!(flag = (t_flags*)malloc(sizeof(t_flags))))
		exit(0);
	flag->is_firstnum = 0;
	flag->first_num = 0;
	flag->second_num = 0;
	flag->is_minus = 0;
	flag->is_plus = 0;
	flag->is_zero = 0;
	flag->is_point = 0;
	flag->is_secondnum = 0;
	flag->is_space = 0;
	flag->is_grid = 0;
	flag->floatzero = 0;
	flag->is_lderror = 0;
	flag->is_longfloat = 0;
	flag->symb_space = ' ';
	flag->symb_zero = '0';
	flag->type = '\0';
	return (flag);
}

t_args		*create_struct_of_args(void)
{
	t_args	*args;

	if (!(args = (t_args*)malloc(sizeof(t_args))))
		exit(0);
	args->str = ft_strnew(0);
	args->symb = ' ';
	return (args);
}

static void	save_firstnum(const char ***s, t_flags *flags, va_list arg)
{
	if (***s == '0')
	{
		flags->is_zero = 1;
		(**s)++;
		while (!(***s >= '0' && ***s <= '9'))
		{
			if ((***s >= 'a' && ***s <= 'z')
					|| (***s >= 'A' && ***s <= 'Z'))
			{
				(**s)--;
				break ;
			}
			else if (***s == '+')
				flags->is_plus = 1;
			else if (***s == '-')
				flags->is_minus = 1;
			(**s)++;
		}
	}
	flags->is_firstnum = 1;
	check_star_for_first(s, flags, arg);
}

static void	save_flags(const char **s, t_flags *flags, va_list arg)
{
	(*s)++;
	while (!((**s >= 'a' && **s <= 'z') || (**s >= 'A' && **s <= 'Z'))
			&& **s != '%' && **s != '\0')
	{
		if (**s == '#')
			flags->is_grid = 1;
		else if (**s == '+')
			flags->is_plus = 1;
		else if (**s == ' ')
			flags->is_space = 1;
		else if (**s == '-')
			flags->is_minus = 1;
		else if (**s == '.')
			flags->is_point = 1;
		else if (((**s >= '0' && **s <= '9') || **s == '*') &&
		flags->is_firstnum == 0 && flags->is_point == 0)
			save_firstnum(&s, flags, arg);
		else if (((**s >= '0' && **s <= '9') || **s == '*') &&
		flags->is_point == 1 && flags->is_secondnum == 0)
		{
			flags->is_secondnum = 1;
			check_star_for_second(s, flags, arg);
		}
		(*s)++;
	}
}

char		*read_str(t_flags *flags, const char *s, va_list arg,
			int *countnull)
{
	t_args	*args;
	char	*print;

	create_var(&flags, &args, &print);
	while (*s != '\0')
	{
		if (*s == '{')
			change_style(&s, args, &print);
		else if (*s == '%')
		{
			save_flags(&s, flags, arg);
			newstr(&print, get_str_numb(read_types(&s), arg, flags, args));
			read_symb(s, args, arg);
			if (*s == 'c')
				return_result_for_c(&countnull, &flags, &print, &args);
			clear_and_create_var(&flags, &args);
			if (*s == '\0')
				break ;
		}
		else
			newstr(&print, ft_strndup(s, 1));
		s++;
	}
	clear_f_a(flags, args);
	return (print);
}
