/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:28:48 by                   #+#    #+#             */
/*   Updated: 2021/10/19 21:11:30 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	print_player(t_var ***game, char c, int x, int y)
{
	if (c == 'R' || c == 'L')
	{
		if ((**game)->elem.player.x != x || (**game)->elem.player.y != y)
			mlx_destroy_image((**game)->mlx, (**game)->elem.player.img);
		if (c == 'R')
			(**game)->elem.player.img = mlx_xpm_file_to_image((**game)->mlx,
					"./textures/player_right.xpm", &(**game)->elem.player.hht,
					&(**game)->elem.player.hht);
		if (c == 'L')
			(**game)->elem.player.img = mlx_xpm_file_to_image((**game)->mlx,
					"./textures/player_left.xpm", &(**game)->elem.player.hht,
					&(**game)->elem.player.hht);
	}
	mlx_put_image_to_window((**game)->mlx, (**game)->win, (**game)->elem
		.player.img, x, y);
	(**game)->elem.player.x = x;
	(**game)->elem.player.y = y;
}

void	move_player(t_var **game, char c, int x, int y)
{
	if ((*game)->map[y / 31][x / 31] == '1')
	{
		print_player(&game, c, (*game)->elem.player.x, (*game)->elem.player.y);
		return ;
	}
	if ((*game)->map[y / 31][x / 31] == 'C')
		(*game)->elem.collect.count--;
	if ((*game)->map[y / 31][x / 31] == 'E' && (*game)->elem.collect.count <= 0)
	{
		print_player(&game, c, x, y);
		destroy_game(&game);
		printf("moves: %d\n", ++(*game)->elem.player.count);
		warning("Finish!\n", 0);
	}
	printf("moves: %d\n", ++(*game)->elem.player.count);
	print_player(&game, c, x, y);
}
