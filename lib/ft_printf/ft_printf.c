/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 16:13:35 by skrabby           #+#    #+#             */
/*   Updated: 2019/11/02 19:10:48 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	t_flags	*flags;
	va_list arg;
	char	*str;
	int		countnull;
	int		count;

	str = NULL;
	flags = NULL;
	countnull = 0;
	va_start(arg, s);
	str = read_str(flags, s, arg, &countnull);
	va_end(arg);
	ft_putstr(str);
	count = ft_strlen(str) + countnull;
	ft_memdel((void**)&str);
	return (count);
}

int	ft_fprintf(int fd, const char *s, ...)
{
	t_flags	*flags;
	va_list arg;
	char	*str;
	int		countnull;
	int		count;

	str = NULL;
	flags = NULL;
	countnull = 0;
	va_start(arg, s);
	str = read_str(flags, s, arg, &countnull);
	va_end(arg);
	ft_putstr_fd(str, fd);
	count = ft_strlen(str) + countnull;
	ft_memdel((void**)&str);
	return (count);
}
