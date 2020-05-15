/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrabby <skrabby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 13:28:07 by skrabby           #+#    #+#             */
/*   Updated: 2019/09/15 15:26:49 by skrabby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countwords(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (s[i] == c)
		while (s[i] == c)
			i++;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			count++;
			while (s[i] == c)
				i++;
		}
		else
		{
			i++;
			if (s[i] == '\0')
				count++;
		}
	}
	return (count);
}

static int		ft_countlen(char const *s, char c, int *i)
{
	int count;
	int k;

	k = *i;
	count = 0;
	while (s[k] != c && s[k] != '\0')
	{
		count++;
		k++;
	}
	return (count);
}

static char		*ft_oneword(char const *s, char c, int *i, char **s2)
{
	char	*str;
	int		j;

	j = 0;
	if (!(str = (char*)malloc(sizeof(char) * (ft_countlen(s, c, i) + 1))))
	{
		while (j < ft_countwords(s, c))
		{
			free(s2[j]);
			j++;
		}
		return (NULL);
	}
	while (s[*i] != c && s[*i] != '\0')
	{
		str[j] = s[*i];
		(*i)++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s || !c)
		return (NULL);
	if (!(str = (char**)malloc(sizeof(char *) * (ft_countwords(s, c) + 1))))
		return (NULL);
	str[ft_countwords(s, c)] = NULL;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		while (j < ft_countwords(s, c))
		{
			str[j] = ft_oneword(s, c, &i, str);
			j++;
			while (s[i] == c)
				i++;
		}
	}
	return (str);
}
