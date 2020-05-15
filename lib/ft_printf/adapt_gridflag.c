/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adapt_gridflag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:22:28 by skrabby           #+#    #+#             */
/*   Updated: 2019/11/27 22:34:00 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		secondnb_handle(t_args *args, t_flags *flags)
{
	if (flags->type == 'f' && !flags->is_minus && flags->is_zero)
		newargsstr(args, ft_strdup(""),
		ft_strempty_symb(flags->first_num, flags->symb_zero));
	else if (flags->first_num > flags->second_num)
		newargsstr(args, ft_strdup(args->str + flags->second_num),
		ft_strempty_symb(flags->second_num, flags->symb_zero));
	else
		newargsstr(args, ft_strdup(""),
		ft_strempty_symb(flags->second_num, flags->symb_zero));
}

void		put_x(char *nb, t_args *args, char symb)
{
	size_t len;

	len = 1;
	if (ft_strlen(args->str) - ft_strlen(nb) > len)
	{
		args->str[1] = symb;
		args->str[0] = '0';
	}
	else
	{
		args->str[0] = symb;
		newargsstr(args, ft_strdup("0"), ft_strdup(args->str));
	}
}

void		paste_ox_to_string(t_args *args)
{
	size_t	count;
	int		l;

	count = ft_strlen(args->str);
	l = count;
	if (count == 1)
	{
		newargsstr(args, ft_strdup("0x"), ft_strdup(args->str));
		return ;
	}
	while (ft_isprint(args->str[count - 1]) && args->str[count - 1] != ' ')
		count--;
	newargsstr(args, ft_strdup("0x"), ft_strdup(args->str + count));
	if (l > (int)ft_strlen(args->str))
	{
		while (l != (int)ft_strlen(args->str))
			newargsstr(args, ft_strdup(" "), ft_strdup(args->str));
	}
}

void		is_gridflag(char *nb, t_flags *flags, t_args *args)
{
	int i;

	i = 0;
	if (flags->type == 'p')
		grid_type_x(nb, flags, args, i);
	if (*nb == '\0')
		return ;
	if (flags->is_grid && (nb[0] != '0') &&
			(flags->type == 'o' || flags->type == 'x' || flags->type == 'X'))
	{
		while (!((args->str[i] >= '0' && args->str[i] <= '9') ||
		(args->str[i] >= 'a' && args->str[i] <= 'f') ||
		(args->str[i] >= 'A' && args->str[i] <= 'F')))
			i++;
		grid_type_o(nb, flags, args, i);
		grid_type_x(nb, flags, args, i);
		grid_type_bigx(nb, flags, args, i);
	}
}
