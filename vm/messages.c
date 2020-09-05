/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 14:13:01 by oelaina           #+#    #+#             */
/*   Updated: 2020/09/05 14:13:07 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_usage(char *exec_name)
{
	ft_printf("Usage: %s [-some flags] <champion.cor> <...>", exec_name);
	exit(1);
}
