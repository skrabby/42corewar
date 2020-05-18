//
// Created by poligon on 18.05.2020.
//

#include "corewar.h"

int str_endswith(char *str, char *end)
{
	int str_len;
	int end_len;

	str_len = ft_strlen(str);
	end_len = ft_strlen(end);
	if (end_len > str_len)
		return (0);
	else
	{
		str = &str[str_len - end_len];
		return (ft_strequ(str, end));
	}
}