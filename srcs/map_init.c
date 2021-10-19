/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:37:50 by                   #+#    #+#             */
/*   Updated: 2021/10/19 23:28:09 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

static void	init_coordinate(t_elements ***elem, int x, int y, char c)
{
	if (c == 'P')
	{
		(**elem)->player.x = x * 31;
		(**elem)->player.y = y * 31;
	}
}

void	add_element(t_var **game, t_elements **elem, const int *cord, char c)
{
	mlx_put_image_to_window((*game)->mlx, (*game)->win, (*elem)->back.img,
		cord[1] * 31, cord[0] * 31);
	if (c == '1')
		mlx_put_image_to_window((*game)->mlx, (*game)->win, (*elem)->wall.img,
			cord[1] * 31, cord[0] * 31);
	if (c == 'C')
	{
		mlx_put_image_to_window((*game)->mlx, (*game)->win,
			(*elem)->collect.img, cord[1] * 31, cord[0] * 31);
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
	int	cord[2];
	int	y;
	int	x;

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

void	map_init(t_var game, int x, int y)
{
	printf("Start!\n");
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, x * 31, y * 31, "so_long");
	game.elem.back.img = mlx_xpm_file_to_image(game.mlx,
			"./textures/background.xpm", &game.elem.back.wth,
			&game.elem.back.hht);
	game.elem.wall.img = mlx_xpm_file_to_image(game.mlx, "./textures/wall.xpm",
			&game.elem.wall.wth, &game.elem.wall.hht);
	game.elem.exit.img = mlx_xpm_file_to_image(game.mlx, "./textures/exit.xpm",
			&game.elem.exit.wth, &game.elem.exit.hht);
	game.elem.collect.img = mlx_xpm_file_to_image(game.mlx,
			"./textures/coin.xpm", &game.elem.collect.wth,
			&game.elem.collect.hht);
	game.elem.player.img = mlx_xpm_file_to_image(game.mlx,
			"./textures/player.xpm", &game.elem.player.wth,
			&game.elem.player.hht);
	game.elem.player.count = 0;
	create_map(&game, &game.elem, game.map);
	move_init(&game);
}
