/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrabby <skrabby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:02:13 by skrabby           #+#    #+#             */
/*   Updated: 2019/09/10 16:00:16 by skrabby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	char *tmp;

	if (!*to_find)
		return ((char*)str);
	while (*str && len > 0)
	{
		if (*str == *to_find)
		{
			tmp = (char*)str;
			while (*str++ == *to_find++ && len-- > 0)
			{
				if (*to_find == '\0')
					return (tmp);
				else if (*str == '\0')
					return (0);
			}
			to_find = to_find - (str - tmp);
			len = len + (str - tmp);
			str = tmp;
		}
		str++;
		len--;
	}
	return (0);
}
