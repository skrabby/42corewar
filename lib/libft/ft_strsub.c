/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 10:37:09 by skrabby           #+#    #+#             */
/*   Updated: 2019/11/06 20:18:14 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	char	*begin;

	if (!s || (ft_strlen(s) < len))
		return (0);
	s2 = (char*)malloc(sizeof(char) * (len + 1));
	if (!s2)
		exit(0);
	s += start;
	begin = s2;
	while (*s && len > 0)
	{
		*s2 = *s;
		s2++;
		s++;
		len--;
	}
	*s2 = '\0';
	return (begin);
}
