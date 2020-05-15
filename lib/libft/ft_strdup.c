/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 09:19:44 by skrabby           #+#    #+#             */
/*   Updated: 2019/11/06 20:00:09 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		length;
	int		i;
	char	*temp;

	i = 0;
	if (str == NULL)
		return (NULL);
	length = ft_strlen(str);
	temp = (char*)malloc(sizeof(char) * (length + 1));
	if (!temp)
		exit(0);
	while (str[i] != '\0')
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
