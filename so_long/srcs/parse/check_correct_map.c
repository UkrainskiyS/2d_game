#include "../../so_long.h"

static int	check_0(char **map)
{
	int i;
	int j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[++j])
		{
			if (map[i][j] == '0')
				return (1);
		}
	}
	return (0);
}

static int	check_c(char **map)
{
	int i;
	int j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C')
				return (1);
		}
	}
	return (0);
}

static int	check_e(char **map)
{
	int i;
	int j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'E')
				return (1);
		}
	}
	return (0);
}

static int	check_p(char **map)
{
	int i;
	int j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
				return (1);
		}
	}
	return (0);
}

int chek_correct_map(char **map)
{
	return (check_p(map) && check_e(map) && check_c(map) && check_0(map));
}
