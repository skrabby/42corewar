/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrabby <skrabby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:06:16 by skrabby           #+#    #+#             */
/*   Updated: 2019/09/06 18:37:48 by skrabby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *tmp;

	tmp = 0;
	if ((*s) == '\0' && (*s) == (char)c)
		tmp = ((char*)(s));
	while (*s != '\0')
	{
		if (*s == (char)c)
			tmp = ((char*)s);
		s++;
		if ((*s) == '\0' && (*s) == (char)c)
			tmp = ((char*)s);
	}
	return (tmp);
}
