/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrabby <skrabby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:31:53 by skrabby           #+#    #+#             */
/*   Updated: 2019/09/06 15:22:09 by skrabby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ps1;
	unsigned char	*ps2;

	ps1 = (unsigned char*)s1;
	ps2 = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (!ps1 && !ps2)
			return (0);
		if (*ps1 == *ps2)
		{
			ps1++;
			ps2++;
			i++;
		}
		else
			return ((int)(*ps1 - *ps2));
	}
	return (0);
}
