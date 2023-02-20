#include "miniRT.h"

int	write_color(int t, t_vec pixel_color)
{
	return (t << 24 | (int)(255 * pixel_color.x) << 16 | (int)(255 * pixel_color.y) << 8 | (int)(255 * pixel_color.z));
}

int	hit_sphere(t_vec center, double radius, t_cam r)
{
	t_vec	oc;
	double	a;
	double	half_b;
	double	c;
	double	discriminant;

	oc = init_vec(r.coor.x - center.x
				,r.coor.y - center.y
				,r.coor.z - center.z);
	a = vec_dot(r.vec, r.vec);
	half_b = vec_dot(oc, r.vec);
	c = vec_dot(oc, oc) - radius * radius;
	discriminant = half_b * half_b - a * c;
 	if (discriminant < 0)
		return (-1);
	else
		return ((-half_b - sqrt(discriminant)) / a);
}

/* int	hit_sphere(t_vec center, double radius, t_cam r)
{
	t_vec	oc;
	double	a;
	double	b;
	double	c;
	double	discriminant;

	oc = init_vec(r.coor.x - center.x
				,r.coor.y - center.y
				,r.coor.z - center.z);
	a = vec_dot(r.vec, r.vec);
	b = 2.0 * vec_dot(oc, r.vec);
	c = vec_dot(oc, oc) - radius * radius;
	discriminant = b * b - 4 * a * c;
 	if (discriminant < 0)
		return (-1);
	else
		return ((-b - sqrt(discriminant)) / (2.0 * a));
} */