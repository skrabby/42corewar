/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelaina <oelaina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:46:16 by skrabby           #+#    #+#             */
/*   Updated: 2019/11/19 19:25:36 by oelaina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_join(char **s, char *buff, const int fd)
{
	char *tmp;

	if (!s[fd])
		s[fd] = ft_strdup(buff);
	else
	{
		tmp = ft_strjoin(s[fd], buff);
		free(s[fd]);
		s[fd] = tmp;
	}
}

static int	ft_setline(char **s, char **line, const int fd)
{
	int		i;
	char	*tmp;

	i = 0;
	if (s[fd] == NULL)
		return (0);
	while (s[fd][i] != '\n' && s[fd][i] != '\0')
		i++;
	if (s[fd][i] == '\n')
	{
		*line = ft_strndup(s[fd], (size_t)i);
		tmp = ft_strdup(s[fd] + i + 1);
		free(s[fd]);
		s[fd] = tmp;
	}
	else if (s[fd][i] == '\0')
	{
		*line = ft_strdup(s[fd]);
		tmp = ft_strdup(s[fd] + i);
		free(s[fd]);
		s[fd] = tmp;
		if (*line[0] == '\0')
			return (0);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*s[FD_SIZE];
	char		buff[BUFF_SIZE + 1];
	int			ret;

	ret = 0;
	if (fd < 0 || !line)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		ft_join(s, buff, fd);
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	if (!(ft_setline(s, line, fd)) && ret == 0 &&
	(!s[fd] || s[fd][0] == '\0'))
		return (0);
	return (1);
}
