#ifndef SO_LONG_H
#define SO_LONG_H

#include "mlx_utils/mlx_utils.h"
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"

#include <fcntl.h>
#include <stdio.h>

#define ESCAPE 53
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
	char		**map;
	void		*mlx;
	void		*win;
	t_elements	elem;
}				t_var;

void	move_player(t_var **game, char c, int x, int y);
void	move_init(t_var *game, char **map);

int		chek_correct_map(char **map);
char	**parse_file(char *file);
void 	*free_map(char **map);

void	add_element(t_var **game, t_elements **elem, const int *cord, char c);
void	create_map(t_var *game, t_elements *elem, char **map);
void	map_init(t_var game, int x, int y);

int		mouse_hook(int button, int x, int y, t_var **game);
int		keyboard_hook(int key, t_var *game);
void	warning(char *str, int code);
#endif
