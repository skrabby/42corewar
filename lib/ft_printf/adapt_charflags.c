/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adapt_charflags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 16:32:08 by skrabby           #+#    #+#             */
/*   Updated: 2019/11/27 19:07:26 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*r_handler(char *s)
{
	char	*new_s;
	char	*tmp;
	int		i;

	i = 0;
	new_s = ft_strnew(0);
	while (s[i])
	{
		tmp = ft_strndup(s + i, 1);
		if (s[i] < ' ' || s[i] > '~')
			newnbtwo(&tmp, ft_strdup(ft_itoa_base_lu(tmp[0], 16)));
		newnbtwo(&new_s, ft_strjoin(new_s, tmp));
		free(tmp);
		i++;
	}
	return (new_s);
}

void	adapt_flags(t_flags *flags, char *nb)
{
	if (flags->is_grid && (flags->type == 'o' || flags->type == 'x'
	|| flags->type == 'X' || flags->type == 'p'))
		flags->is_plus = 0;
	if (flags->is_minus || (flags->is_secondnum && flags->type != 'f'))
		flags->is_zero = 0;
	if (flags->is_plus || nb[0] == '-')
		flags->is_space = 0;
}

void	is_minus_char(t_flags *flags, t_args *args)
{
	int i;

	i = 0;
	if (flags->is_minus)
	{
		while (args->str[i] == ' ')
			i++;
		if (i != 0)
			newargsstr(args, ft_strdup(args->str + i),
			ft_strempty_symb(i, ' '));
	}
}

void	is_firstnum_char(char nb, t_flags *flags, t_args *args)
{
	newargsstr(args, ft_strdup(""), ft_strempty_symb(1, nb));
	if (flags->is_firstnum)
		newargsstr(args, ft_strempty_symb(flags->first_num - 1,
		flags->symb_space), ft_strempty_symb(1, nb));
}

void	is_firstsecond_str(char **nb, t_flags *flags, t_args *args)
{
	if (flags->is_firstnum)
		newargsstr(args, ft_strdup(""),
		ft_strempty_symb(flags->first_num, flags->symb_space));
	if (flags->is_secondnum || flags->is_point)
		newnbtwo(nb, ft_strndup(*nb, flags->second_num));
	if (flags->is_firstnum && flags->first_num > (int)ft_strlen(*nb))
		newargsstr(args, ft_strdup(args->str + ft_strlen(*nb)), ft_strdup(*nb));
	else
		newargsstr(args, ft_strdup(""), ft_strdup(*nb));
}
