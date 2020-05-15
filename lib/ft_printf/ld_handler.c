/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 20:36:29 by skrabby           #+#    #+#             */
/*   Updated: 2019/11/02 18:23:29 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ld_isinfnan(t_ldouble *ld, t_union uf, t_flags *flags)
{
	flags->is_secondnum = 0;
	if (uf.p.mantissa == 0x8000000000000000)
		(*ld).mantstr = flags->type == 'F' ? ft_strdup("INF") :
		ft_strdup("inf");
	else
	{
		flags->is_plus = 0;
		(*ld).mantstr = flags->type == 'F' ? ft_strdup("NAN") :
		ft_strdup("nan");
	}
	flags->is_lderror = 1;
}

static int	handle_error(t_ldouble *ld, t_union uf, t_flags *flags)
{
	if (uf.p.exponent == 32767)
	{
		ld_isinfnan(ld, uf, flags);
		return (1);
	}
	if (flags->is_secondnum == 0 && flags->second_num < 6 && !flags->is_point)
		flags->second_num = 6;
	if (!uf.p.mantissa)
	{
		(*ld).tmp = ft_strempty_symb(flags->second_num, '0');
		(*ld).mantstr = flags->is_point && flags->second_num == 0 ?
		ft_strdup("0") : ft_strjoin("0.", (*ld).tmp);
		if (flags->type == 'e')
			newnbtwo(&(*ld).mantstr, ft_strjoin((*ld).mantstr, "e+00"));
		free((*ld).tmp);
		return (1);
	}
	return (0);
}

static void	set_var(long double nb, t_ldouble *ld, t_union *uf)
{
	(*ld).is_full = 0;
	(*ld).i = 0;
	(*ld).count_e = 0;
	(*ld).nb = nb;
	(*uf).fnum = nb;
	(*ld).pow = (*uf).p.exponent - 16383;
	(*ld).multpow = 62 - (*ld).pow;
	if ((*ld).pow > 63)
	{
		(*ld).pow -= 63;
		(*ld).is_full = 1;
		(*ld).base = "2";
		(*ld).multpow = (*ld).pow - 1;
	}
	else if ((*ld).pow == 63)
		(*ld).base = "1";
	else
		(*ld).base = "5";
}

/*
**	Formula to get long double: (Mantissa * 2^(exponent - 16383) / 2^63,
**	which can be interpreted as:
**	(Mantissa * 5^(63 - (exponent - 16383)))/ (10^(63 - (exponent - 16383)))
*/

char		*handle_float(long double nb, t_flags *flags)
{
	t_union		uf;
	t_ldouble	ld;

	set_var(nb, &ld, &uf);
	if (handle_error(&ld, uf, flags))
		return (ld.mantstr);
	ld.m = ft_strdup(ld.base);
	ld_optimize(&ld);
	mult_pow(&ld);
	ld.mantstr = multiply(ft_strdup(ft_itoa_base_lu(uf.p.mantissa, 10)), ld.m);
	if (flags->is_longfloat && !ld.is_full)
		newnbtwo(&ld.mantstr, ft_strjoin(ld.mantstr, "0"));
	eflag_handler(flags, &ld);
	if (ld.pow >= 0 || (flags->type == 'e' ||
	(flags->type == 'g' && (count_zero(nb, &ld) > 3))))
		putpoint(&ld.mantstr, ld.multpow + flags->is_longfloat
		+ ld.count_e, ld.is_full);
	else
		handle_zero(&ld, uf, flags);
	handle_precision(&ld.mantstr, flags, &ld);
	eflag_adapt(flags, &ld);
	if (uf.p.sign)
		newnbtwo(&ld.mantstr, ft_strjoin("-", ld.mantstr));
	return (ld.mantstr);
}
