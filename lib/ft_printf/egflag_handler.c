/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   egflag_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 02:56:50 by skrabby           #+#    #+#             */
/*   Updated: 2019/11/02 18:23:15 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		gflag_more(char **s, t_prec *p, t_ldouble *ld, t_flags *flags)
{
	flags->second_num -= (*p).i;
	if (!(*ld).is_full)
	{
		(*p).s2 = ft_strndup(*s + (*p).i, flags->second_num + 2);
		round_number(&(*p), (*ld).pow);
	}
	else
	{
		(*p).tmp = ft_strempty_symb(flags->second_num, '0');
		(*p).s2 = ft_strjoin(".", (*p).tmp);
		free((*p).tmp);
	}
}

void		gflag_less(char **s, t_prec *p, t_ldouble *ld, t_flags *flags)
{
	flags->type = 'e';
	free((*p).s1);
	(*p).s1 = ft_strndup((*s), 1);
	if (flags->second_num)
		flags->second_num -= 1;
	eflag_handler(flags, ld);
	if ((*ld).pow < 0)
	{
		(*ld).count_e = count_zero((*ld).nb, &(*ld)) * (-1) - 1;
		if ((*ld).count_z <= 3)
			flags->type = 'g';
	}
	else
		(*ld).count_e = (*p).i - 1;
	(*p).tmp = ft_strdup(".");
	(*p).s2 = !(*ld).is_full ? ft_strndup(*s + 1, flags->second_num + 1) :
		ft_strndup(*s + 1, flags->second_num + 2);
	newnbtwo(&(*p).s2, ft_strjoin((*p).tmp, (*p).s2));
	free((*p).tmp);
	round_number(&(*p), (*ld).pow);
	if ((*p).s1[1] != '\0')
	{
		(*p).s1[1] = '\0';
		(*ld).count_e++;
	}
}

void		eflag_handler(t_flags *flags, t_ldouble *ld)
{
	if (flags->type == 'e')
	{
		(*ld).count_e = 0;
		(*ld).strlen = (int)ft_strlen((*ld).mantstr) - ((*ld).multpow +
		flags->is_longfloat);
		if ((*ld).strlen > 2)
		{
			while ((*ld).strlen-- != 2)
				(*ld).count_e++;
		}
		else if ((*ld).strlen < 2)
		{
			while ((*ld).strlen++ != 2)
				(*ld).count_e--;
		}
		if ((*ld).is_full)
			(*ld).count_e = (int)ft_strlen((*ld).mantstr) - 1;
	}
}

void		eflag_adapt(t_flags *flags, t_ldouble *ld)
{
	if (flags->type == 'e')
	{
		(*ld).tmp = ft_itoa(ft_module((*ld).count_e));
		if ((*ld).count_e >= 0 && (*ld).count_e < 10)
			newnbtwo(&(*ld).tmp, ft_strjoin("e+0", (*ld).tmp));
		else if ((*ld).count_e >= 10)
			newnbtwo(&(*ld).tmp, ft_strjoin("e+", (*ld).tmp));
		else if ((*ld).count_e > -10 && (*ld).count_e < 0)
			newnbtwo(&(*ld).tmp, ft_strjoin("e-0", (*ld).tmp));
		else if ((*ld).count_e <= -10)
			newnbtwo(&(*ld).tmp, ft_strjoin("e-", (*ld).tmp));
		newnbtwo(&(*ld).mantstr, ft_strjoin((*ld).mantstr, (*ld).tmp));
		free((*ld).tmp);
	}
}

void		eflag_full(char **s, t_ldouble *ld, t_flags *flags, t_prec *p)
{
	if ((*ld).is_full && flags->type == 'e')
	{
		(*p).i = 0;
		(*p).s1 = ft_strndup((*s), 1);
		newnbtwo(&(*p).s1, ft_strjoin((*p).s1, "."));
		while ((*s)[(*p).i] != '.')
			(*p).i++;
		(*p).s2 = ft_strndup((*s) + 1, (*p).i - 1);
		newnbtwo(&(*p).s2, ft_strjoin((*p).s2, (*s) + (*p).i + 1));
		newnbtwo(&(*p).s2, ft_strndup((*p).s2, flags->second_num + 1));
		round_number(&(*p), (*ld).pow);
		newnbtwo(&(*s), ft_strjoin((*p).s1, (*p).s2));
		free((*p).s1);
		free((*p).s2);
	}
}
