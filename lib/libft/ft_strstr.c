/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrabby <skrabby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 19:19:14 by skrabby           #+#    #+#             */
/*   Updated: 2019/09/10 15:56:17 by skrabby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	char	*tmp;

	if (!*to_find)
		return ((char*)str);
	while (*str)
	{
		if (*str == *to_find)
		{
			tmp = (char*)str;
			while (*str++ == *to_find++)
			{
				if (*to_find == '\0')
					return (tmp);
				else if (*str == '\0')
					return (0);
			}
			to_find = to_find - (str - tmp);
			str = tmp;
		}
		str++;
	}
	return (0);
}
