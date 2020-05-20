//
// Created by poligon on 18.05.2020.
//

#include "ft_printf.h"
#include "stdlib.h"

void print_usage(char *exec_name)
{
    ft_printf("Usage: %s [-some flags] <champion.cor> <...>", exec_name);
	exit(0);
}