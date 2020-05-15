/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrabby <skrabby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 09:19:44 by skrabby           #+#    #+#             */
/*   Updated: 2019/09/12 12:35:02 by skrabby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	int		length;
	int		i;
	char	*temp;

	i = 0;
	if (ft_strlen(s1) >= n)
		length = n;
	else
		length = ft_strlen(s1);
	temp = (char*)malloc(sizeof(char) * (length + 1));
	if (!temp)
		return (0);
	while (s1[i] != '\0' && n > 0)
	{
		temp[i] = s1[i];
		i++;
		n--;
	}
	temp[i] = '\0';
	return (temp);
}
