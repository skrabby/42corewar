/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 17:56:08 by oelaina           #+#    #+#             */
/*   Updated: 2019/11/02 18:23:13 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		is_color(char *s)
{
	if (!ft_strcmp(s, "red") || !ft_strcmp(s, "green")
	|| !ft_strcmp(s, "yellow") || !ft_strcmp(s, "cyan")
	|| !ft_strcmp(s, "blue") || !ft_strcmp(s, "eoc")
	|| !ft_strcmp(s, "bold") || !ft_strcmp(s, "uline"))
		return (1);
	else
		return (0);
}

static void		to_ansi(char **s)
{
	char	*ansi_color;

	ansi_color = ft_strdup("");
	if (!(ft_strncmp(*s, "red", 3)))
		ansi_color = ft_strdup(RED);
	else if (!(ft_strncmp(*s, "green", 5)))
		ansi_color = ft_strdup(GREEN);
	else if (!(ft_strncmp(*s, "yellow", 6)))
		ansi_color = ft_strdup(YELLOW);
	else if (!(ft_strncmp(*s, "cyan", 4)))
		ansi_color = ft_strdup(CYAN);
	else if (!(ft_strncmp(*s, "blue", 4)))
		ansi_color = ft_strdup(BLUE);
	else if (!(ft_strncmp(*s, "eoc", 3)))
		ansi_color = ft_strdup(EOC);
	else if (!(ft_strncmp(*s, "bold", 4)))
		ansi_color = ft_strdup(BOLD);
	else if (!(ft_strncmp(*s, "uline", 5)))
		ansi_color = ft_strdup(ULINE);
	free(*s);
	*s = ft_strdup(ansi_color);
	free(ansi_color);
}

static void		check_valid(const char **s, char **color, int *i)
{
	while (!(**s == '}') && *i < 7 && **s != 0)
	{
		(*s)++;
		(*i)++;
	}
	if (*s == 0 && *i == 7)
	{
		*s -= *i;
		return ;
	}
	if (**s == '}')
	{
		*s -= *i;
		*color = ft_strsub(*s, 1, *i - 1);
		*s += *i;
	}
}

static void		check_color(t_args *args, const char **s)
{
	char	*color;
	int		i;

	i = 0;
	check_valid(s, &color, &i);
	if (is_color(color))
	{
		to_ansi(&color);
		newargsstr(args, ft_strdup(""), color);
	}
	else
	{
		newargsstr(args, ft_strdup("{"), ft_strdup(""));
		*s -= i;
	}
}

void			change_style(const char **s, t_args *args, char **print)
{
	if (**s == '{')
	{
		check_color(args, s);
		newstr(print, ft_strdup(args->str));
	}
}
