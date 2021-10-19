#include "../so_long.h"

int	mouse_hook(int button, int x, int y, t_var **game)
{
	free_map((*game)->map);
	warning("\0", 0);
	return (0);
}

int keyboard_hook(int key, t_var *game)
{
	if (key == ESCAPE)
		warning("\0", 0);
	return (0);
}

void	warning(char *str, int code)
{
	if (*str != '\0')
		ft_putstr_fd(str, 1);
	exit(code);
}
