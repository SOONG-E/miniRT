#include "miniRT.h"

int	write_color(int t, t_vec pixel_color)
{
	return (t << 24 | (int)(255 * pixel_color.x) << 16 | (int)(255 * pixel_color.y) << 8 | (int)(255 * pixel_color.z));
}

//dir/sphere
//(t_meta meta로 비교)

void	front_face(t_cam r, t_vec normal)
{
	if (vec_dot(r.vec, normal) > 0.0)
	{
		normal = init_vec(-normal.x, -normal.y, -normal.z);
	}
	else
	{
		normal = init_vec(normal.x, normal.y, normal.z);
	}
}

int	hit(t_cam r, double t_min, double t_max, t_hit_record out)
{
	t_vec	oc;
	double	a;
	double	half_b;
	double	c;
	double	discriminant;

	t_vec center = init_vec(0, 0, -1);
	double radius = 0.5;
	oc = init_vec(r.coor.x - center.x
				,r.coor.y - center.y
				,r.coor.z - center.z);
	a = vec_dot(r.vec, r.vec);
	half_b = vec_dot(oc, r.vec);
	c = vec_dot(oc, oc) - (radius * radius);
	discriminant = half_b * half_b - a * c;
 	if (discriminant < 0)
		return (-1);
	double	root;
	double	sqrtd;
	sqrtd = sqrt(discriminant);
	root = (- half_b - sqrtd) / a;
	if (root < t_min || t_max < root)
	{
		root = (-half_b + sqrtd) / a;
		if (root < t_min || t_max < root)
			return (-1);
	}
	out.t = root;
	out.p = ray_at(r, out.t);
	out.normal = init_vec((out.p.x - center.x) / radius,
				(out.p.y - center.y) / radius,
				(out.p.z - center.z) / radius);
	return (1);
}

double	hit_sphere(t_vec center, double radius, t_cam r)
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
	c = vec_dot(oc, oc) - (radius * radius);
	discriminant = half_b * half_b - a * c;
 	if (discriminant < 0)
		return (-1);
	else
		return (- half_b - sqrt(discriminant) / a);
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