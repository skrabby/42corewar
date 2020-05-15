/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strempty_symb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrabby <skrabby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 14:10:52 by skrabby           #+#    #+#             */
/*   Updated: 2019/10/03 20:49:01 by skrabby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strempty_symb(int len, char symb)
{
	int		i;
	char	*temp;

	i = 0;
	temp = (char*)malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (0);
	while (i < len)
	{
		temp[i] = symb;
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
