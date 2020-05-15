/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llu_itoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 17:57:56 by oelaina           #+#    #+#             */
/*   Updated: 2019/11/02 18:23:44 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_len_int(unsigned long long numb, int base)
{
	int i;

	i = 0;
	while (numb >= (unsigned long long)base)
	{
		numb /= (unsigned long long)base;
		i++;
	}
	i++;
	return (i);
}

static long long	ft_mod(unsigned long long numb, int base)
{
	numb %= (unsigned long long)base;
	return (numb);
}

static char			*solve_itoa(unsigned long long numb,
int base, char *digits, char *res)
{
	unsigned long long	*num;
	int					i;
	int					j;

	i = 0;
	j = 0;
	num = (unsigned long long *)malloc(sizeof(unsigned long long) *
	(ft_len_int(numb, base)));
	if (!num)
		exit(-1);
	while (numb >= (unsigned long long)base)
	{
		num[i] = ft_mod(numb, base);
		numb /= (unsigned long long)base;
		i++;
	}
	num[i] = numb;
	while (i >= 0)
	{
		res[j] = digits[num[i]];
		i--;
		j++;
	}
	ft_memdel((void **)&num);
	return (res);
}

char				*ft_itoa_base_lu(unsigned long long numb, int base)
{
	char	*digits;
	char	*res;
	char	*result;

	digits = "0123456789ABCDEF";
	res = ft_strnew(ft_len_int(numb, base));
	if (!res)
		exit(-1);
	result = solve_itoa(numb, base, digits, res);
	free(res);
	return (result);
}

char				*ft_itoa_base_small_lu(unsigned long long numb, int base)
{
	char	*digits;
	char	*res;
	char	*result;

	digits = "0123456789abcdef";
	res = ft_strnew(ft_len_int(numb, base));
	if (!res)
		exit(-1);
	result = solve_itoa(numb, base, digits, res);
	free(res);
	return (result);
}
