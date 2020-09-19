/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrabby <skrabby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 12:18:45 by skrabby           #+#    #+#             */
/*   Updated: 2020/09/19 15:29:28 by skrabby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "config.h"
#include "asm.h"
#include "error.h"

int		is_whitespace(char c)
{
	return (c == '\t'
			|| c == '\v'
			|| c == '\f'
			|| c == '\r'
			|| c == ' ');
}

int		is_delimiter(char c)
{
	return (is_whitespace(c)
			|| c == '\0'
			|| c == '\n'
			|| c == COMMAND_CHAR
			|| c == '\"'
			|| c == DIRECT_CHAR
			|| c == SEPARATOR_CHAR
			|| c == COMMENT_CHAR
			|| c == COMMENT_CHAR_ALT);
}

char	*strjoin_free(t_bool s1_b, t_bool s2_b, char *s1, char *s2)
{
	char *s;

	s = ft_strjoin(s1, s2);
	if (s1_b)
		free(s1);
	if (s2_b)
		free(s2);
	return (s);
}

int		is_register(const char *token)
{
	int	i;

	i = 0;
	if (ft_strlen(token) >= 2 && ft_strlen(token) <= 3 && token[i] == REG_CHAR)
	{
		i++;
		while (ft_isdigit(token[i]))
			i++;
		return (!token[i] && ft_atoi(&token[1]) > 0);
	}
	return (0);
}

void	error_exit(char *error)
{
	ft_printf("%s", error);
	exit(1);
}
