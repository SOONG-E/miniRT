#include "miniRT.h"

static t_vec clamp(t_vec v, double min, double max)
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
	return (out);
}

t_vec ray_at(t_ray ray, double t)
{
	t_vec	out;

	out.x = ray.coor.x + ray.unit_vec.x * t;
	out.y = ray.coor.y + ray.unit_vec.y * t;
	out.z = ray.coor.z + ray.unit_vec.y * t;
	return (out);
}

t_vec	get_lowerleft_corner(t_vec origin, t_bg bg, t_vec w)
{
	// double	focal_length;
	t_vec	corner;

	// focal_length = cam.fov / 180.0;
	corner = vec_sub(origin, vec_div(bg.hori, 2.0));
	corner = vec_sub(corner, vec_div(bg.verti, 2.0));
	corner = vec_sub(corner, w);
	return (corner);
}