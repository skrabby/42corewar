/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrabby <skrabby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 17:42:09 by skrabby           #+#    #+#             */
/*   Updated: 2019/09/12 12:40:57 by skrabby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_llongmax(unsigned long long int nb, int sign)
{
	if (nb > 9223372036854775807)
	{
		if (sign == -1)
			return (0);
		else
			return (-1);
	}
	else
		return (nb * sign);
}

int				ft_atoi(const char *str)
{
	int						i;
	unsigned long long int	result;
	int						sign;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] != '\0')
	{
		while ((str[i] > 0 && str[i] <= 26) || (str[i] > 27 && str[i] < 33))
			i++;
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				sign = sign * (-1);
			i++;
		}
		while (str[i] - '0' >= 0 && str[i] - '0' <= 9)
		{
			result = result * 10 + str[i] - '0';
			i++;
		}
		return (ft_llongmax(result, sign));
	}
	return (ft_llongmax(result, sign));
}
