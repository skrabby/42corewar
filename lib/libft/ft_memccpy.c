/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrabby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:10:17 by skrabby           #+#    #+#             */
/*   Updated: 2019/09/06 10:42:15 by skrabby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*pdst;
	unsigned char	*psrc;

	i = 0;
	pdst = (unsigned char*)dst;
	psrc = (unsigned char*)src;
	while (i < n)
	{
		*pdst = *psrc;
		if (*psrc == (unsigned char)c)
			return (pdst + 1);
		pdst++;
		psrc++;
		i++;
	}
	return (0);
}
