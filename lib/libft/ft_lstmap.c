/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrabby <skrabby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 16:18:03 by skrabby           #+#    #+#             */
/*   Updated: 2019/09/15 15:25:08 by skrabby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(t_list *lst)
{
	t_list *tmp;

	tmp = lst;
	while (tmp)
	{
		tmp->content = NULL;
		tmp->content_size = 0;
		free(tmp);
		tmp = tmp->next;
	}
	lst = NULL;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	*p;
	t_list	*begin;

	if (!lst || !f)
		return (NULL);
	newlst = f(lst);
	if (!(begin = ft_lstnew(newlst->content, newlst->content_size)))
		return (NULL);
	else
		p = begin;
	lst = lst->next;
	while (lst)
	{
		newlst = f(lst);
		if (!(p->next = ft_lstnew(newlst->content, newlst->content_size)))
		{
			ft_free(begin);
			return (NULL);
		}
		p = p->next;
		lst = lst->next;
	}
	return (begin);
}
