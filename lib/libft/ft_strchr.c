/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrabby <skrabby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 17:59:38 by skrabby           #+#    #+#             */
/*   Updated: 2019/09/06 18:30:10 by skrabby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if ((*s) == '\0' && (*s) == (char)c)
		return ((char*)(s));
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char*)s);
		s++;
		if ((*s) == '\0' && (*s) == (char)c)
			return ((char*)s);
	}
	return (0);
}
