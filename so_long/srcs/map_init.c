#include "../so_long.h"

static void	init_coordinate(t_elements ***elem, int x, int y, char c)
{
	if (c == '1')
	{
		(**elem)->wall.x = x * 31;
		(**elem)->wall.y = y * 31;
	}
	if (c == 'C')
	{
		(**elem)->collect.x = x * 31;
		(**elem)->collect.y = y * 31;
	}
	if (c == 'E')
	{
		(**elem)->exit.x = x * 31;
		(**elem)->exit.y = y * 31;
	}
	if (c == 'P')
	{
		(**elem)->player.x = x * 31;
		(**elem)->player.y = y * 31;
	}
}

void	add_element(t_var **game, t_elements **elem, const int *cord, char c)
{
	if (c == '1')
		mlx_put_image_to_window((*game)->mlx, (*game)->win, (*elem)->wall.img,
								cord[1] * 31, cord[0] * 31);
	else
		mlx_put_image_to_window((*game)->mlx, (*game)->win, (*elem)->back.img,
								cord[1] * 31, cord[0] * 31);
	if (c == 'C')
	{
		mlx_put_image_to_window((*game)->mlx, (*game)->win, (*elem)->collect.img,
								cord[1] * 31, cord[0] * 31);
		(*elem)->collect.count++;
	}
	if (c == 'E')
		mlx_put_image_to_window((*game)->mlx, (*game)->win, (*elem)->exit.img,
								cord[1] * 31, cord[0] * 31);
	if (c == 'P')
		mlx_put_image_to_window((*game)->mlx, (*game)->win, (*elem)->player.img,
								cord[1] * 31, cord[0] * 31);
	init_coordinate(&elem, cord[1], cord[0], c);
}

void	create_map(t_var *game, t_elements *elem, char **map)
{
	int cord[2];
	int y;
	int x;

	elem->collect.count = 0;
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

void map_init(t_var game, int x, int y)
{
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, x * 31, y * 31, "so_long");
	game.elem.back.img = mlx_xpm_file_to_image(game.mlx,"./images/background.xpm",
								&game.elem.back.wth, &game.elem.back.hht);
	game.elem.wall.img = mlx_xpm_file_to_image(game.mlx,"./images/wall.xpm",
								&game.elem.wall.wth, &game.elem.wall.hht);
	game.elem.exit.img = mlx_xpm_file_to_image(game.mlx,"./images/exit.xpm",
								&game.elem.exit.wth, &game.elem.exit.hht);
	game.elem.collect.img = mlx_xpm_file_to_image(
					game.mlx,"./images/coin.xpm", &game.elem.collect.wth,
					&game.elem.collect.hht);
	game.elem.player.img = mlx_xpm_file_to_image(
			game.mlx,"./images/player_right.xpm", &game.elem.player.wth,
			&game.elem.player.hht);
	game.elem.player.count = 0;
	create_map(&game, &game.elem, game.map);
	move_init(&game, game.map);
}