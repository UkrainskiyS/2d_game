#include "../../so_long.h"

int move(int key, t_var *game)
{
	if (key == UP || key == LEFT || key == DOWN || key == RIGHT)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->elem.back.img,
								game->elem.player.x, game->elem.player.y);
		if (key == UP)
			print_player(&game, 'W', game->elem.player.x,
						 game->elem.player.y - 31);
		if (key == LEFT)
			print_player(&game, 'L', game->elem.player.x - 31,
						 game->elem.player.y);
		if (key == DOWN)
			print_player(&game, 'S', game->elem.player.x,
						 game->elem.player.y + 31);
		if (key == RIGHT)
			print_player(&game, 'R', game->elem.player.x + 31,
						 game->elem.player.y);
	}
	return (0);
}

int render(t_var *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->elem.player.img,
							game->elem.player.x, game->elem.player.y);
	return (0);
}

void	move_init(t_var *game, char **map)
{
	mlx_loop_hook(game->mlx, render, game);
	mlx_key_hook(game->win, move, game);

	mlx_loop(game->mlx);
}

