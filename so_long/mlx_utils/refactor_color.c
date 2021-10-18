#include "mlx_utils.h"

int add_shade(double range, int trgb)
{
	int r;
	int g;
	int b;

	if (range == 0.0)
		return (trgb);
	r = get_r(trgb) >> 16;
	g = get_g(trgb) >> 8;
	b = get_b(trgb);
	if (range == 1.0)
		return (create_trgb(255, r, g, b));
	return (create_trgb((int)(255 * range), r, g, b));
}

int get_opposite(int color)
{
	return (get_t(color) | get_r(color) | get_g(color) | get_b(color));
}
