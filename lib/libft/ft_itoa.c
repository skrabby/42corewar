/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrabby <skrabby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:56:47 by skrabby           #+#    #+#             */
/*   Updated: 2019/09/12 16:00:39 by skrabby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_revstr(char *s, int len)
{
	char	temp;
	char	*begin;
	char	*end;
	int		i;

	i = 0;
	begin = s;
	end = s;
	while (i++ < len - 1)
		end++;
	if (s[0] == '-')
		begin++;
	i = 0;
	while (i < len / 2)
	{
		temp = *begin;
		*begin = *end;
		*end = temp;
		begin++;
		end--;
		i++;
	}
}

static int	ft_checklen_int(int n)
{
	int count;

	count = 0;
	if (n < 0)
		count++;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	len = ft_checklen_int(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(str = ft_strnew(len)))
		return (0);
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
		i++;
	}
	while (i < len)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	str[i] = '\0';
	ft_revstr(str, len);
	return (str);
}
