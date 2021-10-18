#include "mlx_utils.h"

int close_game(int keycode, t_var *vars)
{
	if (keycode == 53)
		mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}
