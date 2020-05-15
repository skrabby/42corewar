/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrabby <skrabby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 10:35:51 by skrabby           #+#    #+#             */
/*   Updated: 2019/09/10 14:11:54 by skrabby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t					i;
	unsigned char			*pdst;
	const unsigned char		*psrc;

	pdst = (unsigned char*)dst;
	psrc = (unsigned char*)src;
	if (dst == NULL && src == NULL)
		return (0);
	i = 0;
	if (psrc < pdst)
		while (i++ < len)
			pdst[len - i] = psrc[len - i];
	else
		while (i++ < len)
			*pdst++ = *psrc++;
	return (dst);
}
