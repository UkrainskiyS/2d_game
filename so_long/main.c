#include "so_long.h"

void	error(char *str)
{
	ft_putstr_fd(str, 1);
	exit(1);
}

int main()
{
	char	**map;
	int 	x;
	int 	y;

	map = parse_file("map_big.ber");
	if (!map)
		error("Error\n");
	x = (int) ft_strlen(map[0]);
	y = -1;
	while (map[++y]);
	map_init(map, x, y);
	free_map(map, y);
	return (0);
}
