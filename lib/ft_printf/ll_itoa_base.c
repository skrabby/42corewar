/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 16:12:37 by oelaina           #+#    #+#             */
/*   Updated: 2019/11/02 18:23:42 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			write_in_num(long long *num,
int *i, long long numb, int base)
{
	while (numb >= (long long)base || numb <= -(long long)base)
	{
		num[*i] = ft_mod_ll(numb, base);
		ft_div_ll(&numb, base);
		(*i)++;
	}
	num[*i] = modul(numb);
}

static char			*solve_itoa_ll(long long numb,
int base, long long *num, char *digits)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	i = 0;
	if (numb < 0)
		res = (char *)malloc(sizeof(char) * ((ft_len_int_ll(numb, base)) + 2));
	else
		res = (char *)malloc(sizeof(char) * ((ft_len_int_ll(numb, base)) + 1));
	if (!res)
		exit(-1);
	if (numb < 0 && base == 10)
		res[j++] = '-';
	write_in_num(num, &i, numb, base);
	while (i >= 0)
	{
		res[j] = digits[num[i]];
		i--;
		j++;
	}
	res[j] = '\0';
	return (res);
}

char				*ft_itoa_base_ll(long long numb, int base)
{
	char		*digits;
	long long	*num;
	char		*res;

	digits = "0123456789ABCDEF";
	num = (long long *)malloc(sizeof(long long) * (ft_len_int_ll(numb, base)));
	if (!num)
		exit(-1);
	res = solve_itoa_ll(numb, base, num, digits);
	ft_memdel((void **)&num);
	return (res);
}
