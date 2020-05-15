/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrabby <skrabby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 14:21:20 by skrabby           #+#    #+#             */
/*   Updated: 2019/09/13 14:23:11 by skrabby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstreverse(t_list **begin_list)
{
	t_list *p;
	t_list *c;
	t_list *n;

	p = NULL;
	c = *begin_list;
	while (c != NULL)
	{
		n = c->next;
		c->next = p;
		p = c;
		c = n;
	}
	*begin_list = p;
}
