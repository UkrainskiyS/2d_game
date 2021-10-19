#include "so_long.h"

int main(int argc, char **argv)
{
	t_var	game;
	int 	x;
	int 	y;

	if (argc != 2)
		warning("Incorrect arguments!\n", 1);
	game.map = parse_file(argv[1]);
	if (!game.map)
		warning("Error\n", 1);
	x = (int) ft_strlen(game.map[0]);
	y = -1;
	while (game.map[++y]);
	map_init(game, x, y);
	free_map(game.map);
	return (0);
}
