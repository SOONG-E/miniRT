#include "miniRT.h"

t_vec clamp(t_vec v, double min, double max)
{
	if (v.x < min)
		v.x = min;
	if (v.y < min)
		v.y = min;
	if (v.z < min)
		v.z = min;
	if (max < v.x)
		v.x = max;
	if (max < v.y)
		v.y = max;
	if (max < v.z)
		v.z = max;
	return (v);
}

int	color_to_int(int t, t_vec pixel_color)
{
	pixel_color = vec_mul(pixel_color, 255.0);
	pixel_color = clamp(pixel_color, 0.0, 255.0);
	return (t << 24 | (int)(pixel_color.x) << 16 | (int)(pixel_color.y) << 8 | (int)(pixel_color.z));
}

t_vec	vec_min(t_vec a, t_vec b)
{
	(void)b;
	t_vec	out;

	out.x = 255;
	out.y = 255;
	out.z = 255;

	if (a.x < out.x)
		out.x = a.x;
	if (a.y < out.y)
		out.y = a.y;
	if (a.z < out.z)
		out.z = a.z;
	// out.x = min(a.x, b.x);
	// out.y = min(a.y, b.y);
	// out.z = min(a.z, b.z);
	return (out);
}