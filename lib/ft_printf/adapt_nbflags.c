/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adapt_nbflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:03:27 by skrabby           #+#    #+#             */
/*   Updated: 2019/11/02 18:23:06 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	is_plusflag(char *nb, t_flags *flags, t_args *args, int i)
{
	if (flags->is_plus)
	{
		if (flags->is_firstnum && flags->first_num > (int)ft_strlen(nb))
		{
			while (!(args->str[i] >= '0'
			&& args->str[i] <= '9') && args->str[i] && !flags->is_lderror)
				i++;
			while (flags->is_lderror && args->str[i] == ' ')
				i++;
			if (i == 0 && !flags->is_zero)
				newargsstr(args, ft_strdup("+"), ft_strdup(args->str));
			else if (nb[0] != '-')
			{
				if (flags->is_zero && (flags->type != 'f' || flags->type != 'e'
				|| !flags->is_minus))
					args->str[i] = '+';
				else
					args->str[i - 1] = '+';
			}
			else
				args->str[i - 1] = '-';
		}
		else if (nb[0] != '-')
			newargsstr(args, ft_strdup("+"), ft_strdup(args->str));
	}
}

void	is_secondnum_sign(char *nb, t_flags *flags, t_args *args, int i)
{
	if (flags->is_secondnum && nb[0] != '-')
		newargsstr(args, ft_strndup(args->str,
		(size_t)ft_negativezero((int)ft_strlen(args->str) -
		(int)ft_strlen(nb))), ft_strdup(nb));
	else if ((flags->is_secondnum || flags->is_zero) && nb[0] == '-')
	{
		if (flags->is_zero == 0)
			newargsstr(args, ft_strndup(args->str,
			(size_t)ft_negativezero((int)ft_strlen(args->str) -
			(int)ft_strlen(nb + 1))), ft_strdup(nb + 1));
		else
			newargsstr(args, ft_strndup(args->str,
			(size_t)ft_negativezero((int)ft_strlen(args->str) -
			(int)ft_strlen(nb))), ft_strdup(nb + 1));
		while (!(args->str[i] >= '0' && args->str[i] <= '9'))
			i++;
		if (i == 0)
			newargsstr(args, ft_strdup("-"), ft_strdup(args->str));
		else
			args->str[i - 1] = '-';
	}
}

void	is_minus_nb(char *nb, t_flags *flags, t_args *args, int i)
{
	if (flags->is_minus)
	{
		while (args->str[i] == ' ')
			i++;
		if (flags->is_space && i != 0 && !flags->is_plus)
			i--;
		else if (flags->is_space && i == 0 && !flags->is_plus)
			newargsstr(args, ft_strdup(" "), ft_strdup(args->str));
		if (i != 0 && !((flags->type == 'f' || flags->type == 'e')
		&& nb[0] == '-' && flags->is_zero))
			newargsstr(args, ft_strdup(args->str + i),
			ft_strempty_symb(i, ' '));
		else if (i != 0 && ((flags->type == 'f' || flags->type == 'e') &&
		nb[0] == '-' && flags->is_zero))
			newargsstr(args, ft_strdup(args->str + i),
			ft_strempty_symb(i + 1, ' '));
	}
	if (flags->is_space)
	{
		if (args->str[0] == ' ' || (args->str[0] == '0' && flags->is_zero))
			args->str[0] = ' ';
		else
			newargsstr(args, ft_strdup(" "), ft_strdup(args->str));
	}
}

void	is_secondnum_nb(char *nb, t_flags *flags, t_args *args)
{
	if (flags->is_secondnum || ((flags->type == 'f' || flags->type == 'e') &&
	!flags->is_minus && flags->is_zero))
		secondnb_handle(args, flags);
	else if (flags->is_zero && flags->type != 'f' && flags->type != 'e'
	&& flags->is_space == 0)
		newargsstr(args, ft_strdup(""),
		ft_strempty_symb(flags->first_num, flags->symb_zero));
	else if (flags->is_zero && flags->type != 'f' && flags->type != 'e'
	&& flags->is_space == 1)
	{
		newargsstr(args, ft_strdup(""),
		ft_strempty_symb(flags->first_num - 1, flags->symb_zero));
		newargsstr(args, ft_strdup(" "), ft_strdup(args->str));
	}
	if (!flags->is_secondnum && flags->is_firstnum)
		newargsstr(args, ft_strdup(""),
		ft_strjoin(args->str + ft_strlen(nb), nb));
}

void	is_firstnum_nb(char **nb, t_flags *flags, t_args *args)
{
	char *savenb;

	savenb = ft_strdup(*nb);
	if ((*nb)[0] == '0' && flags->is_point &&
	(!flags->is_grid || flags->type != 'o') && flags->type != 'f'
	&& flags->type != 'e')
		newnb(&nb, ft_strdup(""), flags);
	newargsstr(args, ft_strdup(""), ft_strdup(*nb));
	if (flags->is_firstnum == 1)
		newargsstr(args, ft_strdup(""),
		ft_strempty_symb(flags->first_num, flags->symb_space));
	if (**nb == '\0' && flags->type != 'f' && flags->type != 'e')
		newnbtwo(&savenb, ft_strdup(""));
	newnb(&nb, savenb, flags);
}
