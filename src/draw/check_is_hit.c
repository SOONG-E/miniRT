#include "miniRT.h"

t_vec ray_at(t_ray ray, double t)
{
	t_vec	out;

	out.x = ray.coor.x + ray.unit_vec.x * t;
	out.y = ray.coor.y + ray.unit_vec.y * t;
	out.z = ray.coor.z + ray.unit_vec.y * t;
	return (out);
}

void	front_face(t_ray ray, t_record *rec)
{
	if (vec_dot(ray.unit_vec, rec->normal) < 0.0)
		return ;
	rec->normal = vec_mul(rec->normal, -1);
}

int	hit_sphere(t_obj obj, t_ray ray, t_record *rec)
{
	t_vec	oc;
	double	a;
	double	half_b;
	double	discriminant;
	double	root;

	oc = vec_sub(ray.coor, obj.coor);
	a = length_squared(ray.unit_vec);
	half_b = vec_dot(oc, ray.unit_vec);
	discriminant = half_b * half_b - a * (vec_dot(oc, oc) - (obj.ratio * obj.ratio));
	if (discriminant < 0)
		return (FALSE);
	root = (-half_b - sqrt(discriminant)) / a;
	if (root < T_MIN || root > rec->t_max)
	{
		root = (-half_b + sqrt(discriminant)) / a;
		if (root < T_MIN || root > rec->t_max)
			return (FALSE);
	}
	rec->t_max = root;
	rec->p = ray_at(ray, rec->t_max);
	rec->normal = vec_div(vec_sub(rec->p, obj.coor), obj.ratio);
	rec->albedo = obj.rgb;
	front_face(ray, rec);
	return (TRUE);
}

int	hit_plane(t_obj obj, t_ray ray, t_record *rec)
{
	float	numrator;
	float	denominator;
	float	root;

	denominator = vec_dot(ray.unit_vec, obj.vec);
	if (fabs(denominator) < T_MIN)
		return (FALSE);
	numrator = vec_dot(vec_sub(obj.coor, ray.coor), obj.vec);
	root = numrator / denominator;
	if (root < T_MIN || root > rec->t_max)
		return (FALSE);
	rec->t_max = root;
	rec->p = ray_at(ray, rec->t_max);
	rec->normal = obj.vec;
	front_face(ray, rec);
	rec->albedo = obj.rgb;
	return (TRUE);
}

int	hit_cylinder(t_obj obj, t_ray ray, t_record *rec)
{
	int	result;

	result = 0;
	// result += hit_cylinder_cap(obj, ray, rec, obj.cylin.height / 2);
	// result += hit_cylinder_cap(obj, ray, rec, -(obj.cylin.height / 2));
	result = hit_cylinder_side(obj, ray, rec);
	// if (result == 0)
	// 	return TRUE;
	return result;
}
