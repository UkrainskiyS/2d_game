#include "../so_long.h"

void	add_element(t_var **game, t_elements **elem, const int *cord, char c)
{
	if (c == '1')
	{
		mlx_put_image_to_window((*game)->mlx, (*game)->win, (*elem)->wall.img,
								cord[1] * 31, cord[0] * 31);
	}
	else
		mlx_put_image_to_window((*game)->mlx, (*game)->win, (*elem)->back.img,
								cord[1] * 31, cord[0] * 31);
	if (c == 'C')
		mlx_put_image_to_window((*game)->mlx, (*game)->win, (*elem)->collect.img,
								cord[1] * 31, cord[0] * 31);
	if (c == 'E')
		mlx_put_image_to_window((*game)->mlx, (*game)->win, (*elem)->exit.img,
								cord[1] * 31, cord[0] * 31);
	if (c == 'P')
		mlx_put_image_to_window((*game)->mlx, (*game)->win, (*elem)->player.img,
								cord[1] * 31, cord[0] * 31);
}

void	create_map(t_var *game, t_elements *elem, char **map)
{
	int cord[2];
	int y;
	int x;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			cord[0] = y;
			cord[1] = x;
			add_element(&game, &elem, cord, map[y][x]);
		}
	}
}

void map_init(char **map, int x, int y)
{
	t_var		game;
	t_elements	elem;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, x * 31, y * 31, "so_long");
	elem.back.img = mlx_xpm_file_to_image(game.mlx,"./images/background.xpm",
								&elem.back.img_width, &elem.back.img_height);
	elem.wall.img = mlx_xpm_file_to_image(game.mlx,"./images/wall.xpm",
								&elem.wall.img_width, &elem.wall.img_height);
	elem.exit.img = mlx_xpm_file_to_image(game.mlx,"./images/exit.xpm",
								&elem.exit.img_width, &elem.exit.img_height);
	elem.collect.img = mlx_xpm_file_to_image(
			game.mlx,"./images/coin.xpm", &elem.collect.img_width,
			&elem.collect.img_height);
	elem.player.img = mlx_xpm_file_to_image(
			game.mlx,"./images/player_right.xpm", &elem.player.img_width,
			&elem.player.img_height);
	create_map(&game, &elem, map);
	mlx_loop(game.mlx);
}