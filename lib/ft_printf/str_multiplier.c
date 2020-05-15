/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_multiplier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 17:44:34 by skrabby           #+#    #+#             */
/*   Updated: 2019/11/02 19:05:23 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			mult_pow(t_ldouble *ld)
{
	while ((*ld).i++ < (*ld).multpow)
	{
		(*ld).tmp = multiply((*ld).m, ft_strdup((*ld).base));
		(*ld).m = ft_strdup((*ld).tmp);
		free((*ld).tmp);
	}
}

static	int		set_value(t_multstr *ms, char *num1, char *num2)
{
	(*ms).len1 = (int)ft_strlen(num1);
	(*ms).len2 = (int)ft_strlen(num2);
	if ((*ms).len1 == 0 || (*ms).len2 == 0 || num1[0] == '0' || num2[0] == '0')
		return (0);
	(*ms).result = (int *)malloc(sizeof(int) * ((*ms).len1 + (*ms).len2 + 1));
	(*ms).i = 0;
	while ((*ms).i++ < (*ms).len1 + (*ms).len2)
		(*ms).result[(*ms).i] = 0;
	(*ms).i_n1 = 0;
	(*ms).i_n2 = 0;
	return (1);
}

static	void	save_result(t_multstr *ms, char *num1, char *num2)
{
	(*ms).i = (*ms).len1 - 1;
	while ((*ms).i >= 0)
	{
		(*ms).carry = 0;
		(*ms).n1 = num1[(*ms).i] - '0';
		(*ms).i_n2 = 0;
		(*ms).j = (*ms).len2 - 1;
		while ((*ms).j >= 0)
		{
			(*ms).n2 = num2[(*ms).j] - '0';
			(*ms).sum = (*ms).n1 * (*ms).n2 +
			(*ms).result[(*ms).i_n1 + (*ms).i_n2] + (*ms).carry;
			(*ms).carry = (*ms).sum / 10;
			(*ms).result[(*ms).i_n1 + (*ms).i_n2] = (*ms).sum % 10;
			(*ms).i_n2++;
			(*ms).j--;
		}
		if ((*ms).carry > 0)
			(*ms).result[(*ms).i_n1 + (*ms).i_n2] += (*ms).carry;
		(*ms).i--;
		(*ms).i_n1++;
	}
	(*ms).i = (*ms).len1 + (*ms).len2 - 1;
}

char			*multiply(char *num1, char *num2)
{
	t_multstr ms;

	if (!set_value(&ms, num1, num2))
		return (ft_strdup("0"));
	save_result(&ms, num1, num2);
	while (ms.i >= 0 && ms.result[ms.i] == 0)
		ms.i--;
	if (ms.i == -1)
		return (ft_strdup("0"));
	ms.s = (char *)malloc(sizeof(char) * (ms.len1 + ms.len2 + 1));
	ms.s[ms.i + 1] = '\0';
	while (ms.i >= 0)
	{
		ms.s[ms.i] = ms.result[ms.i] + '0';
		ms.i--;
	}
	ft_strreverse(ms.s, ft_strlen(ms.s));
	free(num1);
	free(num2);
	free(ms.result);
	return (ms.s);
}
