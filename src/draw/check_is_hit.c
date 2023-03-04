#include "miniRT.h"

void	front_face(t_ray ray, t_rec *rec)
{
	if (0.0 < vec_dot(ray.unit_vec, rec->normal))
		rec->normal = vec_mul(rec->normal, -1);
}

int	hit_sphere(t_obj obj, t_ray ray, t_rec *rec)
{
	t_vec	oc;
	double	a;
	double	half_b;
	double	discriminant;
	double	root;

	oc = vec_sub(ray.coor, obj.coor);
	a = length_squared(ray.unit_vec);
	half_b = vec_dot(oc, ray.unit_vec);
	discriminant = half_b * half_b - a \
					* (length_squared(oc) - (obj.ratio * obj.ratio));
	if (discriminant < 0)
		return (FALSE);
	root = (-half_b - sqrt(discriminant)) / a;
	if (root < T_MIN || root > rec->t_max)
	{
		root = (-half_b + sqrt(discriminant)) / a;
		if (root < T_MIN || rec->t_max < root)
			return (FALSE);
	}
	rec->t_max = root;
	rec->p = ray_at(ray, root);
	rec->normal = vec_unit(vec_sub(rec->p, obj.coor));
	rec->obj = obj;
	front_face(ray, rec);
	return (TRUE);
}

int	hit_plane(t_obj obj, t_ray ray, t_rec *rec)
{
	double	root;

	root = vec_dot(vec_sub(obj.coor, ray.coor), obj.vec) \
			/ vec_dot(ray.unit_vec, obj.vec);
	if (fabs(vec_dot(ray.unit_vec, obj.vec)) < T_MIN)
		return (FALSE);
	if (root < T_MIN || rec->t_max < root)
		return (FALSE);
	rec->t_max = root;
	rec->p = ray_at(ray, root);
	rec->normal = obj.vec;
	front_face(ray, rec);
	rec->obj = obj;
	return (TRUE);
}

/* int	hit_cylinder(t_obj obj, t_ray ray, t_rec *rec)
{
	int	result;

	result = 0;
	result += hit_cylinder_cap(obj, ray, rec, (obj.cylin.height / 2));
	obj.cylin.top_center = vec_add(obj.coor, vec_mul(obj.vec, obj.cylin.height));
	result += hit_cylinder_cap(obj, ray, rec, -(obj.cylin.height / 2));
	obj.cylin.bottom_center = vec_add(obj.coor, vec_mul(obj.vec, -(obj.cylin.height)));
	result += hit_cylinder_side(obj, ray, rec);
	if (result > 3)
		return (TRUE);
	return (FALSE);
}
 */

int	hit_cylinder(t_obj obj, t_ray ray, t_rec *rec)
{
	int	result;

	result = 0;
	result = hit_cylinder_side(obj, ray, rec);
	if (result == TRUE)
		return (result);
	result = hit_cylinder_cap(obj, ray, rec, (obj.cylin.height / 2));
	if (result == TRUE)
		return (result);
	result = hit_cylinder_cap(obj, ray, rec, -(obj.cylin.height / 2));
	if (result == TRUE)
		return (result);
	return (FALSE);
}

int	is_hit(t_meta meta, t_ray ray, t_rec *rec)
{
	int	result;
	int	idx;

	result = FALSE;
	idx = -1;
	while (++idx < meta.obj_num)
	{
		if (meta.hits[meta.objs[idx].type](meta.objs[idx], ray, rec) == TRUE)
			result = TRUE;
	}
	return (result);
}
