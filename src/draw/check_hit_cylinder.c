#include "miniRT.h"

int	hit_cylinder_cap(t_obj obj, t_ray ray, t_rec *rec, double height)
{
	double	r;
	double	diameter;
	double	root;
	t_vec	center;

	r = (double)obj.cylin.diameter / 2;
	center = vec_add(obj.coor, vec_mul(obj.vec, height));
	root = vec_dot(vec_sub(center, ray.coor), obj.vec) \
			/ vec_dot(ray.unit_vec, obj.vec);
	diameter = vec_length(vec_sub(center, ray_at(ray, root)));
	if (fabs(r) < fabs(diameter))
		return (FALSE);
	if (root < T_MIN || rec->t_max < root)
		return (FALSE);
	rec->t_max = root;
	rec->p = ray_at(ray, root);
	rec->normal = obj.vec;
	if (height <= 0)
		rec->normal = vec_mul(rec->normal, -1);
	front_face(ray, rec);
	rec->obj = obj;
	return (TRUE);
}

static double	cy_boundary(t_obj obj, t_vec at_point)
{
	double	len;

	len = sqrt(pow(obj.cylin.diameter / 2, 2.0) + pow(obj.cylin.height / 2, 2.0));
	if (len < vec_length(vec_sub(obj.coor, at_point)))
		return FALSE;
	return TRUE;
}

static t_vec	get_normal(t_obj obj, t_vec at_point)
{
	t_vec	temp;
	t_vec	normal;

	temp = vec_sub(at_point, obj.coor);
	normal = vec_sub(temp, vec_mul(obj.vec, vec_dot(obj.vec, temp)));
	normal = vec_unit(normal);
	return normal;
}

static t_discriminant	discriminate_cylinder(t_obj obj, t_ray ray)
{
	t_vec			oc;
	t_discriminant	disc;

	oc = vec_sub(ray.coor, obj.coor);
	disc.a = length_squared(vec_cross(ray.unit_vec, obj.vec));
	disc.b = vec_dot(vec_cross(ray.unit_vec, obj.vec), vec_cross(oc, obj.vec));
	disc.c = length_squared(vec_cross(oc, obj.vec)) - pow(obj.cylin.diameter / 2, 2);
	disc.disc = pow(disc.b, 2) - disc.a * disc.c;
	disc.sqrtd = sqrt(disc.disc);

	return disc;
}

int	hit_cylinder_side(t_obj obj, t_ray ray, t_rec *rec)
{
	t_discriminant	disc;
	double			root;

	disc = discriminate_cylinder(obj, ray);
	if (disc.disc < 0)
		return (FALSE);
	root = (-disc.b - disc.sqrtd) / disc.a;
	if (root < T_MIN || rec->t_max < root)
	{
		root = (-disc.b + disc.sqrtd) / disc.a;
		if (root < T_MIN || rec->t_max < root)
			return (FALSE);
	}
	if (cy_boundary(obj, ray_at(ray, root)) == FALSE)
		return (FALSE);
	rec->t_max = root;
	rec->p = ray_at(ray, root);
	rec->normal = get_normal(obj, rec->p);
	front_face(ray, rec);
	rec->obj = obj;
	return (TRUE);
}
