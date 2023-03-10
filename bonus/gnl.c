/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtasia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:17:41 by vtasia            #+#    #+#             */
/*   Updated: 2022/04/07 10:18:35 by vtasia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	*gnl_reminder(char *rem, char **line)
{
	char	*p_n;

	p_n = ((void *)0);
	if (*rem)
	{
		p_n = ft_strchr(rem, '\n');
		if (p_n)
		{
			*p_n = '\0';
			*line = ft_strdup(rem);
			rem = ft_strcpy(rem, ++p_n);
		}
		else
		{
			*line = ft_strdup(rem);
			*rem = '\0';
		}
	}
	else
		*line = ft_strdup("");
	return (p_n);
}

static int	gnl_read(char *rem, char *buf, char **line, int fd)
{
	char	*tmp;
	char	*p_n;
	int		r;

	r = 1;
	p_n = ((void *)0);
	while (!p_n && r)
	{
		r = read(fd, buf, 42);
		if (r == 0)
			return (0);
		buf[r] = '\0';
		p_n = ft_strchr(buf, '\n');
		if (p_n)
		{
			*p_n = '\0';
			rem = ft_strcpy(rem, ++p_n);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp);
		if (!(*line))
			return (-1);
	}
	return (1);
}

int	gnl(int fd, char **line)
{
	static char	remainder[42 + 1];
	char		buffer[42 + 1];
	char		*tmp;

	if (42 < 0 || fd < 0 || !line || \
		read(fd, buffer, 0) != 0)
	{
		if (line)
			*line = ((void *)0);
		return (-1);
	}
	tmp = gnl_reminder(remainder, line);
	if (!(*line))
		return (-1);
	if (tmp)
		return (1);
	return (gnl_read(remainder, buffer, line, fd));
}
