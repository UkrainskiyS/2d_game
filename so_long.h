/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:29:37 by                   #+#    #+#             */
/*   Updated: 2021/10/19 15:31:26 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "srcs/gnl/get_next_line.h"
# include "libft/libft.h"

# include <stdio.h>
# include <fcntl.h>

# define ESCAPE 53
# define UP 13
# define LEFT 0
# define RIGHT 2
# define DOWN 1

typedef struct s_data
{
	void	*img;
	int		x;
	int		y;
	int		wth;
	int		hht;
	int		count;
}			t_data;

typedef struct s_elements
{
	t_data	back;
	t_data	wall;
	t_data	collect;
	t_data	exit;
	t_data	player;
}			t_elements;

typedef struct s_var
{
	char		**map;
	void		*mlx;
	void		*win;
	t_elements	elem;
}				t_var;

int		move_render(int key, t_var *game);
void	move_player(t_var **game, char c, int x, int y);
void	move_init(t_var *game);

int		chek_correct_map(char **map);
char	**parse_file(char *file);
void	*free_map(char **map);

void	add_element(t_var **game, t_elements **elem, const int *cord, char c);
void	create_map(t_var *game, t_elements *elem, char **map);
void	map_init(t_var game, int x, int y);

void	destroy_game(t_var ***game);
int		mouse_hook(t_var **game);
int		keyboard_hook(int key, t_var **game);
void	warning(char *str, int code);
#endif
