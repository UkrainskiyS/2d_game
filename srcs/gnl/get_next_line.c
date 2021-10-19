/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:05:11 by                   #+#    #+#             */
/*   Updated: 2021/10/12 14:50:40 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char	*concatenate_line(char **line, char *next, int save)
{
	char	*res;
	size_t	size_l;
	size_t	size_n;

	if (!*line || save)
	{
		size_n = ft_strlen(next) + 1;
		res = (char *) malloc(size_n * sizeof(*next));
		ft_strlcpy(res, next, size_n);
	}
	else
	{
		size_l = ft_strlen(*line);
		size_n = ft_strlen(next);
		res = (char *) malloc((size_l + size_n + 1) * sizeof(char *));
		ft_strlcpy(res, *line, size_l + 1);
		ft_strlcat(res, next, size_l + size_n + 1);
		free(*line);
	}
	if (save)
		free(*line);
	return (res);
}

static int	line_in_save(char **line, char **save_n)
{
	char	*p;

	if (ft_strchr(*save_n, '\n'))
	{
		p = ft_strchr(*save_n, '\n');
		*p = '\0';
		*line = concatenate_line(&*line, *save_n, 0);
		*line = concatenate_line(&*line, "\n", 0);
		*save_n = concatenate_line(&*save_n, ++p, 1);
		return (0);
	}
	else
	{
		if (ft_strlen(*save_n))
			*line = concatenate_line(&*line, *save_n, 0);
		free(*save_n);
		*save_n = NULL;
		return (1);
	}
}

static int	ft_read(int *reads, int fd, char **buf)
{
	*reads = read(fd, *buf, BUFFER_SIZE);
	return (*reads);
}

static char	*run_get_next_line(int fd, int *flag, char *buf, char **save_n)
{
	int			reads;
	char		*line;
	char		*p;

	line = NULL;
	if (*save_n)
		*flag = line_in_save(&line, &*save_n);
	while (*flag && ft_read(&reads, fd, &buf) > 0)
	{
		buf[reads] = '\0';
		if (ft_strchr(buf, '\n'))
		{
			p = ft_strchr(buf, '\n');
			if (reads == 1)
				return ((line = concatenate_line(&line, buf, 0)));
			*p = '\0';
			*save_n = concatenate_line(&*save_n, ++p, 0);
			line = concatenate_line(&line, buf, 0);
			return ((line = concatenate_line(&line, "\n", 0)));
		}
		line = concatenate_line(&line, buf, 0);
	}
	if ((!reads && *flag && !line) || reads == -1)
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		buf[BUFFER_SIZE + 1];
	int			flag;
	static char	*save_n;

	flag = 1;
	line = run_get_next_line(fd, &flag, buf, &save_n);
	return (line);
}
