/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrabby <skrabby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 21:07:58 by skrabby           #+#    #+#             */
/*   Updated: 2019/09/11 16:09:16 by skrabby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	char	*s2;
	int		i;

	if (s && f)
	{
		len = ft_strlen(s);
		i = 0;
		s2 = (char*)malloc(sizeof(*s2) * (len + 1));
		if (!s2)
			return (0);
		while (s[i] != '\0')
		{
			s2[i] = f(i, s[i]);
			i++;
		}
		s2[i] = '\0';
		return (s2);
	}
	return (NULL);
}
