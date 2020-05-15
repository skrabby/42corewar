/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrabby <skrabby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:12:48 by skrabby           #+#    #+#             */
/*   Updated: 2019/09/12 10:47:39 by skrabby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int		begin;
	unsigned int		end;

	end = 0;
	begin = 0;
	if (!s)
		return (NULL);
	if (*s == '\0')
		return (ft_strnew(0));
	while ((s[begin] == ' ' || s[begin] == '\t' || s[begin] == '\n')
	&& s[begin])
		begin++;
	end = ft_strlen(s);
	while ((s[end - 1] == ' ' || s[end - 1] == '\t' || s[end - 1] == '\n')
	&& begin < end)
		end--;
	return (ft_strsub(s, begin, (size_t)(end - begin)));
}
