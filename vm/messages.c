//
// Created by poligon on 18.05.2020.
//

#include "ft_printf.h"
#include "stdlib.h"

void print_usage(char *filename)
{
    ft_printf("Usage: %s [-some flags] <champion.cor> <...>", filename);
	exit(0);
}