/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrabby <skrabby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 17:42:09 by skrabby           #+#    #+#             */
/*   Updated: 2019/09/12 16:04:48 by skrabby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strreverse(char *s, int len)
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
