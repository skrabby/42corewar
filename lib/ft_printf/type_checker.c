/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 19:32:46 by oelaina           #+#    #+#             */
/*   Updated: 2019/11/02 18:23:56 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				char_checker(char *str, char c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

char			*read_types(char const **str)
{
	char	*types;
	int		i;
	char	*res_type;

	i = 0;
	types = ft_strdup("diuUoxXfFeEgGaAcspnbr%");
	while (!(char_checker(types, **str)) && **str != 0)
	{
		(*str)++;
		i++;
	}
	i++;
	if ((**str == '%' || **str == ' ' || **str == 0) && i > 1)
	{
		if (**str == '%')
			(*str)--;
		while (!(char_checker("hlLjz%", **str)))
			(*str)--;
		res_type = ft_strdup("");
	}
	else
		res_type = ft_strsub(*str - i + 1, 0, i);
	free(types);
	return (res_type);
}

static	void	find_sp(char **s)
{
	int		i;
	char	n_s;

	i = 0;
	if (ft_strchr(*s, 's') || ft_strchr(*s, 'p'))
	{
		while (!(char_checker("sp", **s)))
		{
			(*s)++;
			i++;
		}
		if (*s == NULL)
		{
			*s -= i;
			return ;
		}
		n_s = **s;
		*s -= i;
		free(*s);
		*s = ft_strnew(1);
		**s = n_s;
	}
}

char			*get_str_numb(char *s, va_list arg,
						t_flags *flags, t_args *args)
{
	char	*print;

	print = "";
	if (s == NULL)
		return ("");
	if (ft_strchr(s, 'c'))
	{
		while (!(char_checker("c", *s)))
			s++;
		return (print);
	}
	find_sp(&s);
	get_final_char(s, arg, flags, args);
	if (char_checker("%plLjzhdioUuXxsfFbegr", *s))
	{
		free(s);
		return (ft_strjoin(print, args->str));
	}
	free(s);
	return (print);
}
