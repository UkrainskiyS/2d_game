/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:25:23 by                   #+#    #+#             */
/*   Updated: 2021/10/19 21:55:20 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	main(int argc, char **argv)
{
	t_var	game;
	size_t	len;
	int		x;
	int		y;

	if (argc != 2)
		warning("Incorrect arguments!\n", 1);
	len = ft_strlen(argv[1]);
	if (len < 5 || argv[1][len - 1] != 'r' || argv[1][len - 2] != 'e'
		|| argv[1][len - 3] != 'b' || argv[1][len - 4] != '.')
		warning("Error\n", 1);
	game.map = parse_file(argv[1]);
	if (!game.map)
		warning("Error\n", 1);
	x = (int) ft_strlen(game.map[0]);
	y = 0;
	while (game.map[y])
		y++;
	map_init(game, x, y);
	return (0);
}
