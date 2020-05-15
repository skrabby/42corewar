/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrabby <skrabby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:24:41 by skrabby           #+#    #+#             */
/*   Updated: 2019/09/10 12:43:43 by skrabby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t lendst;
	size_t lensrc;
	size_t result;
	size_t i;

	i = 0;
	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	if (size <= lendst)
		result = lensrc + size;
	else
		result = lensrc + lendst;
	while (src[i] != '\0' && (lendst + 1) < size)
	{
		dst[lendst] = src[i];
		i++;
		lendst++;
	}
	dst[lendst] = '\0';
	return (result);
}
