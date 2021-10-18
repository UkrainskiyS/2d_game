#ifndef MLX_UTILS_H
# define MLX_UTILS_H

# include "../mlx/mlx.h"

# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define LIGHT_GREEN 0x64FF96

typedef struct	s_var
{
	void	*mlx;
	void	*win;
}			t_var;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int 	bits_per_pixel;
	int 	line_length;
	int 	endian;
	int		img_width;
	int		img_height;
}			t_data;

int 	close_game(int keycode, t_var *vars);

void 	add_background(t_data *data, int with, int length, int color);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

int 	add_shade(double range, int trgb);
int 	get_opposite(int trgb);

int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);
#endif