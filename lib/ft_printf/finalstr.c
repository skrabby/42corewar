/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finalstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 16:23:56 by skrabby           #+#    #+#             */
/*   Updated: 2019/11/02 18:23:58 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		final_nbstr(char *nb, t_flags *flags, t_args *args)
{
	int i;

	i = 0;
	adapt_flags(flags, nb);
	is_firstnum_nb(&nb, flags, args);
	is_secondnum_nb(nb, flags, args);
	is_secondnum_sign(nb, flags, args, i);
	is_plusflag(nb, flags, args, i);
	is_gridflag(nb, flags, args);
	is_minus_nb(nb, flags, args, i);
	free(nb);
}

void		final_charstr(char *nb, t_flags *flags, t_args *args)
{
	if (nb == NULL)
		nb = ft_strdup("(null)");
	is_firstsecond_str(&nb, flags, args);
	is_minus_char(flags, args);
	free(nb);
}

void		final_charsymb(char nb, t_flags *flags, t_args *args)
{
	is_firstnum_char(nb, flags, args);
	is_minus_char(flags, args);
}

void		final_percent(char nb, t_flags *flags, t_args *args)
{
	is_firstnum_char(nb, flags, args);
	if (flags->is_zero && !flags->is_minus)
		newargsstr(args,
		ft_strempty_symb(flags->first_num - 1, '0'), ft_strdup("%"));
	is_minus_char(flags, args);
}
