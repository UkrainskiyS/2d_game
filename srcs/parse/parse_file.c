/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:41:39 by                   #+#    #+#             */
/*   Updated: 2021/10/19 15:42:55 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../so_long.h"

static int	check_right(char **map)
{
	size_t	j;
	int		i;

	i = 0;
	j = ft_strlen(map[0]) - 1;
	while (map[i])
	{
		if (map[i][j] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	check_left(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	check_file(char **map)
{
	size_t	len;
	int		i;
	int		j;

	len = ft_strlen(map[0]);
	i = 0;
	while (map[++i])
	{
		if (len < 2 || ft_strlen(map[i]) != len)
			return (0);
	}
	j = -1;
	while (map[0][++j])
	{
		if (map[i - 1][j] != '1' || map[0][j] != '1')
			return (0);
	}
	return (check_right(map) && check_left(map) && chek_correct_map(map));
}

char	**parse_file(char *file)
{
	char	**map;
	char	*line;
	int		i;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	i = -1;
	map = (char **) malloc(100 * sizeof(file));
	line = get_next_line(fd);
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		map[++i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	map[i + 1] = NULL;
	close(fd);
	if (!check_file(map) || i < 2)
		return (free_map(map));
	return (map);
}
