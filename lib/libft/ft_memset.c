/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrabby <skrabby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 10:10:08 by skrabby           #+#    #+#             */
/*   Updated: 2019/09/10 13:41:16 by skrabby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int fill, size_t n)
{
	unsigned char	*p;

	p = (unsigned char*)str;
	while (n > 0)
	{
		*p = (unsigned char)fill;
		p++;
		n--;
	}
	return (str);
}
