#ifndef SO_LONG_H
#define SO_LONG_H

#include "mlx_utils/mlx_utils.h"
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"

#include <fcntl.h>
#include <stdio.h>

#define UP 13
#define LEFT 0
#define RIGHT 2
#define DOWN 1

typedef struct s_elements
{
	t_data 	back;
	t_data 	wall;
	t_data	collect;
	t_data	exit;
	t_data	player;
}			t_elements;

typedef struct	s_var
{
	void		*mlx;
	void		*win;
	t_elements	elem;
}				t_var;

void	move_init(t_var *game, char **map);

char	**parse_file(char *file);
void 	*free_map(char **map, int len);

void	print_player(t_var **game, char c, int x, int y);
void	add_element(t_var **game, t_elements **elem, const int *cord, char c);
void	create_map(t_var *game, t_elements *elem, char **map);
void	map_init(char **map, int x, int y);


void	error(char *str);
#endif
