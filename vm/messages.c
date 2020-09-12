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

# define MESSAGE "Usage: %s [-d N -s N -v N |" \
"-n --stealth] [-a] <champion1.cor> <...>\n" \
"    -a        : Prints output from \"aff\" (Default is to hide it)\n" \
"#### TEXT OUTPUT MODE ####################################################\n" \
"    -d N      : Dumps memory after N cycles then exits\n" \
"    -s N      : Runs N cycles, dumps memory, pauses, then repeats\n" \
"    -v N      : Verbosity levels, can be added together to enable several\n" \
"                - 0 : Show only essentials\n" \
"                - 1 : Show lives\n" \
"                - 2 : Show cycles\n" \
"                - 4 : Show operations (Params are NOT litteral ...)\n" \
"#### SELECT PLAYERS NUMBER ################################################\n" \
"    -n N cahmp.cor: Gives number N to the champion\n" \
"##########################################################################"

void	print_usage(char *exec_name)
{
	ft_printf(MESSAGE, exec_name);
	exit(1);
}
