/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 19:36:01 by skrabby           #+#    #+#             */
/*   Updated: 2019/11/02 18:33:40 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_zero(t_ldouble *ld, t_union uf, t_flags *flags)
{
	char		*s1;

	count_zero(uf.fnum, &(*ld));
	if (flags->type == 'g')
	{
		flags->type = 'f';
		flags->second_num += (*ld).count_z;
	}
	if (!(s1 = ft_strempty_symb((*ld).count_z, '0')))
		exit(0);
	newnbtwo(&s1, ft_strjoin("0.", s1));
	newnbtwo(&(*ld).mantstr, ft_strjoin(s1, (*ld).mantstr));
	free(s1);
}

void		putpoint(char **s, int pad, int is_full)
{
	int		len;
	char	*s1;
	char	*s2;

	if (!is_full)
	{
		len = ft_strlen(*s);
		s1 = ft_strndup(*s, len - pad - 1);
		s2 = ft_strdup(*s + (len - pad - 1));
		newnbtwo(&s2, ft_strjoin(".", s2));
		newnbtwo(&(*s), ft_strjoin(s1, s2));
		free(s1);
		free(s2);
	}
	else
		newnbtwo(&(*s), ft_strjoin(*s, "."));
}

static void	round_addnum(t_prec *p, int pow)
{
	if (pow >= 0)
	{
		if (!((*p).s2[(*p).i + 1] == '5' && (*p).s2[(*p).i] % 2 == 0) ||
		(*p).isfive)
			(*p).s2[(*p).i] += 1;
	}
	else
	{
		if ((*p).wasnine && (*p).s2[(*p).i] == '0')
		{
			(*p).tmp = ft_strjoin("1", (*p).s2 + (*p).i + 2);
			(*p).tmp2 = ft_strndup((*p).s2, (*p).i + 1);
			free((*p).s2);
			(*p).s2 = ft_strjoin((*p).tmp2, (*p).tmp);
			free((*p).tmp);
			free((*p).tmp2);
		}
		else
			((*p).s2)[(*p).i] += 1;
	}
}

static void	round_int(t_prec *p)
{
	(*p).wasnine = 0;
	(*p).i = 0;
	while ((*p).s1[(*p).i] != '\0')
		(*p).i++;
	(*p).i--;
	while ((*p).s1[(*p).i] == '9' && (*p).i >= 0)
	{
		(*p).wasnine = 1;
		(*p).s1[(*p).i] = '0';
		(*p).i--;
	}
	if ((*p).s1[0] == '0' && (*p).wasnine)
	{
		(*p).tmp = ft_strdup((*p).s1);
		free((*p).s1);
		(*p).s1 = ft_strjoin("1", (*p).tmp);
		free((*p).tmp);
	}
	else
	{
		if (!((*p).s2[1] == '5' && (*p).s1[(*p).i] % 2 == 0))
			(*p).s1[(*p).i] += 1;
	}
}

void		round_number(t_prec *p, int pow)
{
	(*p).i = 0;
	(*p).wasnine = 0;
	while ((*p).s2[(*p).i] != '\0')
		(*p).i++;
	(*p).i--;
	if ((*p).s2[(*p).i] >= '5')
	{
		(*p).i--;
		while ((*p).s2[(*p).i] == '9')
		{
			(*p).wasnine = 1;
			(*p).s2[(*p).i] = '0';
			(*p).i--;
		}
		(*p).s2[(*p).i] == '.' ? round_int(p) : round_addnum(p, pow);
	}
	(*p).tmp = ft_strndup((*p).s2, ft_strlen((*p).s2) - 1);
	free((*p).s2);
	(*p).s2 = ft_strdup((*p).tmp);
	free((*p).tmp);
}
