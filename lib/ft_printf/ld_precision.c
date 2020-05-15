/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 20:55:45 by skrabby           #+#    #+#             */
/*   Updated: 2019/11/02 18:23:35 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			count_zero(long double nb, t_ldouble *ld)
{
	(*ld).count_z = 0;
	while ((unsigned long long)(nb * 10) % 10 == 0)
	{
		nb = (nb * 10);
		(*ld).count_z++;
	}
	return ((*ld).count_z);
}

static int	check_five(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != '0')
			return (1);
		i++;
	}
	return (0);
}

static void	not_match(char **s, t_prec *p, t_flags *flags)
{
	if ((int)ft_strlen((*p).s2) - 1 != flags->second_num)
	{
		(*p).tmp = ft_strempty_symb(flags->second_num -
				(ft_strlen((*p).s2) - 1), '0');
		(*p).tmp2 = ft_strjoin((*p).s2, (*p).tmp);
		free((*p).s2);
		(*p).s2 = ft_strdup((*p).tmp2);
		free((*p).tmp);
		free((*p).tmp2);
	}
	free(*s);
	if (flags->is_point && !flags->second_num && !flags->is_grid)
		*s = ft_strdup((*p).s1);
	else if (flags->is_point && flags->is_grid && !flags->is_secondnum)
		*s = ft_strjoin((*p).s1, ".");
	else
		*s = ft_strjoin((*p).s1, (*p).s2);
	free((*p).s1);
	free((*p).s2);
}

static void	set_values(char **s, t_prec *p, t_ldouble *ld, t_flags *flags)
{
	(*p).i = 0;
	(*p).isfive = 0;
	while ((*s)[(*p).i] != '.')
		(*p).i++;
	if ((*p).i > 15)
		(*ld).is_full = 1;
	(*p).s1 = ft_strndup(*s, (*p).i);
	if ((*s)[(*p).i + flags->second_num + 1] == '5')
		(*p).isfive = check_five((*s) + (*p).i + flags->second_num + 2);
}

void		handle_precision(char **s, t_flags *flags, t_ldouble *ld)
{
	t_prec p;

	set_values(s, &p, ld, flags);
	if (flags->type == 'g')
	{
		if (flags->second_num >= p.i)
			gflag_more(s, &p, &(*ld), flags);
		else
			gflag_less(s, &p, &(*ld), flags);
	}
	else if (!(*ld).is_full)
	{
		p.s2 = ft_strndup(*s + p.i, flags->second_num + 2);
		round_number(&p, (*ld).pow);
	}
	else
	{
		p.tmp = ft_strempty_symb(flags->second_num, '0');
		p.s2 = ft_strjoin(".", p.tmp);
		free(p.tmp);
	}
	not_match(&(*s), &p, flags);
	eflag_full(&(*s), ld, flags, &p);
}
