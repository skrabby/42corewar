/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 14:12:26 by oelaina           #+#    #+#             */
/*   Updated: 2020/09/05 14:12:30 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <errno.h>

void	error_exit(char *message, char *filename)
{
	if (errno == 0)
	{
		ft_putstr_fd(message, 2);
		ft_putendl_fd(filename, 2);
	}
	else
		write(2, message, ft_strlen(message));
	exit(1);
}
