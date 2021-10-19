/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:35:15 by                   #+#    #+#             */
/*   Updated: 2021/10/19 16:27:17 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	destroy_game(t_var ***game)
{
	free_map((**game)->map);
	mlx_destroy_image((**game)->mlx, (**game)->elem.player.img);
	mlx_destroy_image((**game)->mlx, (**game)->elem.back.img);
	mlx_destroy_image((**game)->mlx, (**game)->elem.wall.img);
	mlx_destroy_image((**game)->mlx, (**game)->elem.collect.img);
	mlx_destroy_image((**game)->mlx, (**game)->elem.exit.img);
	mlx_destroy_window((**game)->mlx, (**game)->win);
}

void	*free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (NULL);
}

int	mouse_hook(t_var **game)
{
	destroy_game(&game);
	warning("Exit!\n", 0);
	return (0);
}

int	keyboard_hook(int key, t_var **game)
{
	if (key == ESCAPE)
	{
		destroy_game(&game);
		warning("Exit!\n", 0);
	}
	return (0);
}

void	warning(char *str, int code)
{
	if (*str != '\0')
		ft_putstr_fd(str, 1);
	exit(code);
}
