/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:58:12 by skrabby           #+#    #+#             */
/*   Updated: 2019/11/06 20:18:46 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*mem;

//	if (size == SIZE_MAX)
//		return (0);
	mem = (char*)malloc(sizeof(char) * (size + 1));
	if (!mem)
		exit(0);
	ft_bzero(mem, size + 1);
	return (mem);
}
