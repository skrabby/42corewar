/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:20:29 by oelaina           #+#    #+#             */
/*   Updated: 2019/11/02 18:23:46 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		newstr(char **str, char *add)
{
	char *tmp;

	if (!(tmp = ft_strjoin(*str, add)))
		exit(0);
	free(*str);
	if (!(*str = ft_strdup(tmp)))
		exit(0);
	free(tmp);
	if (*add)
		free(add);
}

void		newnb(char ***nb, char *tmp, t_flags *flags)
{
	if (**nb && flags->type != 'x' && flags->type != 'u' &&
	flags->type != 'U' &&
	flags->type != 'o' && flags->type != 'X' && flags->type != 'p'
	&& flags->type != 'b')
		free(**nb);
	if (!(**nb = ft_strdup(tmp)))
		exit(0);
	free(tmp);
}

void		newnbtwo(char **nb, char *tmp)
{
	ft_memdel((void**)&(*nb));
	if (!(*nb = ft_strdup(tmp)))
		exit(0);
	free(tmp);
}

void		newargsstr(t_args *args, char *s1, char *s2)
{
	free(args->str);
	if (!(args->str = ft_strjoin(s1, s2)))
		exit(0);
	free(s1);
	free(s2);
}
