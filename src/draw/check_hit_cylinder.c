#include "miniRT.h"

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

int	hit_cylinder_side(t_obj obj, t_ray ray, t_rec *rec)
{
	double	a;
	double	half_b;
	double	c;
	double	discriminant;
	double	root;

	a = length_squared(vec_cross(ray.unit_vec, obj.vec));
	half_b = vec_dot(vec_cross(ray.unit_vec, obj.vec), \
			vec_cross(vec_sub(ray.coor, obj.coor), obj.vec));
	c = length_squared(vec_cross(vec_sub(ray.coor, obj.coor), obj.vec)) \
			- pow(obj.cylin.diameter / 2, 2);
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (FALSE);
	root = (-half_b - sqrt(discriminant)) / a;
	if (root < T_MIN || rec->t_max < root)
	{
		root = (-half_b + sqrt(discriminant)) / a;
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
