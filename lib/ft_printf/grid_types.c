/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_types.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 22:57:35 by oelaina           #+#    #+#             */
/*   Updated: 2019/11/02 18:23:23 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	grid_type_o(char *nb, t_flags *flags, t_args *args, int i)
{
	size_t len;

	len = 0;
	if (flags->type == 'o' && i == 0 && (ft_strlen(args->str)
	== ft_strlen(nb)))
		newargsstr(args, ft_strdup("0"), ft_strdup(args->str));
	else if (flags->type == 'o' && i >= 0 && (ft_strlen(args->str) -
	ft_strlen(nb) > len) && flags->is_zero)
		args->str[0] = '0';
	else if (flags->type == 'o' && i > 0 &&
	!(args->str[i] == '0' && (flags->is_zero || flags->is_point)))
		args->str[i - 1] = '0';
}

void	grid_type_x(char *nb, t_flags *flags, t_args *args, int i)
{
	size_t len;

	len = 0;
	if ((flags->type == 'x' || (flags->type == 'p' && *nb != '0'))
	&& i == 0 && (ft_strlen(args->str)
	== ft_strlen(nb) || flags->second_num > flags->first_num))
		newargsstr(args, ft_strdup("0x"), ft_strdup(args->str));
	else if (flags->type == 'p' && args->str != 0)
		paste_ox_to_string(args);
	else if (flags->type == 'x' && i >= 0 && (ft_strlen(args->str)
	- ft_strlen(nb) > len) && flags->is_zero)
		put_x(nb, args, 'x');
	else if ((flags->type == 'x' || flags->type == 'p') && i > 0)
	{
		args->str[i - 1] = 'x';
		i--;
		if (i != 0)
			args->str[i - 1] = '0';
		else if (i == 0)
			newargsstr(args, ft_strdup("0"), ft_strdup(args->str));
	}
}

void	grid_type_bigx(char *nb, t_flags *flags, t_args *args, int i)
{
	size_t len;

	len = 0;
	if (flags->type == 'X' && i == 0 && (ft_strlen(args->str)
	== ft_strlen(nb) || flags->second_num > flags->first_num))
		newargsstr(args, ft_strdup("0X"), ft_strdup(args->str));
	else if (flags->type == 'X' && i >= 0 && (ft_strlen(args->str)
	- ft_strlen(nb) > len) && flags->is_zero)
		put_x(nb, args, 'X');
	else if (flags->type == 'X' && i > 0)
	{
		args->str[i - 1] = 'X';
		i--;
		if (i != 0)
			args->str[i - 1] = '0';
		else if (i == 0)
			newargsstr(args, ft_strdup("0"), ft_strdup(args->str));
	}
}
