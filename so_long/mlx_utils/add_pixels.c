#include "mlx_utils.h"

void	add_background(t_data *data, int with, int length, int color)
{
	int x;
	int y;

	y = 0;
	while (y < with)
	{
		x = 0;
		while (x < length)
		{
			my_mlx_pixel_put(data, x, y, color);
			x++;
		}
		y++;
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
