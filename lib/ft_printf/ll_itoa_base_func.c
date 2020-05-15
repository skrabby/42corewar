/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_itoa_base_func.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 19:20:03 by oelaina           #+#    #+#             */
/*   Updated: 2019/11/02 18:23:40 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				modul(long long numb)
{
	if (numb < 0)
		return (numb *= -1);
	return (numb);
}

int				ft_len_int_ll(long long numb, int base)
{
	int i;

	i = 0;
	while (numb >= (long long)base || numb <= -(long long)base)
	{
		numb /= (long long)base;
		i++;
	}
	i++;
	return (i);
}

void			ft_div_ll(long long *numb, int base)
{
	*numb /= (long long)base;
	if (*numb < 0)
		*numb *= -1;
}

long long		ft_mod_ll(long long numb, int base)
{
	numb %= base;
	if (numb < 0)
	{
		numb *= -1;
		return (numb);
	}
	return (numb);
}
