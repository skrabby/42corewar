/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrabby <skrabby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:09:26 by skrabby           #+#    #+#             */
/*   Updated: 2019/09/06 14:31:18 by skrabby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*psrc;

	i = 0;
	psrc = (unsigned char*)src;
	while (i < n)
	{
		if (*psrc == (unsigned char)c)
			return (psrc);
		psrc++;
		i++;
	}
	return (0);
}
