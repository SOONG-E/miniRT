#include "miniRT.h"

t_vec	init_vec(double x, double y, double z)
{
	t_vec	out;

	out.x = x;
	out.y = y;
	out.z = z;
	return (out);
}

t_ray	init_ray(t_vec coor, t_vec	unit_vec)
{
	t_ray	out;

	out.coor = coor;
	out.unit_vec = unit_vec;
	return (out);
}

t_rec	init_rec(void)
{
	t_rec	out;

	out.t_max = __DBL_MAX__;
	return (out);
}
