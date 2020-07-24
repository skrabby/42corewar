//
// Created by poligon on 18.05.2020.
//

#include "corewar.h"
#include <errno.h>
#include <stdio.h>


void error_exit(char *message, char *filename)
{
	if (errno == 0)
	{
		ft_putstr_fd(message, 2);
		ft_putendl_fd(filename, 2);
	}
	else
		perror(message);
	exit(1);
}