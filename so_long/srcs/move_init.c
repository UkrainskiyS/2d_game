#include "../so_long.h"

int move_render(int key, t_var *game)
{
	if (key == UP || key == LEFT || key == DOWN || key == RIGHT)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->elem.back.img,
								game->elem.player.x, game->elem.player.y);
		if (game->elem.exit.x == game->elem.player.x
						&& game->elem.exit.y == game->elem.player.y)
			mlx_put_image_to_window(game->mlx, game->win, game->elem.exit.img,
									game->elem.player.x, game->elem.player.y);
		if (key == UP)
			move_player(&game, 'W', game->elem.player.x,
						 game->elem.player.y - 31);
		if (key == LEFT)
			move_player(&game, 'L', game->elem.player.x - 31,
						 game->elem.player.y);
		if (key == DOWN)
			move_player(&game, 'S', game->elem.player.x,
						 game->elem.player.y + 31);
		if (key == RIGHT)
			move_player(&game, 'R', game->elem.player.x + 31,
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
	mlx_hook(game->win, 2, 0L<<2, keyboard_hook, &game);
	mlx_hook(game->win, 17, 1L<<3, mouse_hook, &game);
	mlx_loop_hook(game->mlx, render, game);
	mlx_key_hook(game->win, move_render, game);

	mlx_loop(game->mlx);
}
