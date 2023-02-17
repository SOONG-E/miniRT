#include "miniRT.h"

t_vec	init_vec(double x, double y, double z)
{
	t_vec out;

	out.x = x;
	out.y = y;
	out.z = z;
	return (out);
}

t_rgb	init_rgb(int r, int g, int b)
{
	t_rgb	out;

	out.r = r;
	out.g = g;
	out.b = b;
	return (out);
}