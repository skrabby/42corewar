/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 10:37:09 by skrabby           #+#    #+#             */
/*   Updated: 2019/11/06 20:16:40 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;

	if (s1 && s2)
	{
		if (!(s3 = (char*)malloc(sizeof(s2) * (ft_strlen(s1) +
		ft_strlen(s2) + 1))))
			exit(0);
		if (!s3)
			return (0);
		ft_strcpy(s3, s1);
		ft_strcat(s3, s2);
		return (s3);
	}
	return (NULL);
}
