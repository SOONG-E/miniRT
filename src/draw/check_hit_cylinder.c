#include "miniRT.h"

static int	cy_boundary(t_obj obj, t_vec at_point)
{
	double	hit_height;
	double	max_height;

	hit_height = vec_dot(vec_sub(at_point, obj.coor), obj.vec);
	max_height = obj.cylin.height / 2;
	if (fabs(hit_height) < max_height)
		return (TRUE);
	return (FALSE);
}

static t_vec	get_normal(t_obj obj, t_vec at_point, double height)
{
	t_vec	hit_center;
	t_vec	normal;

	hit_center = vec_add(obj.coor, vec_mul(obj.vec, height));
	normal = vec_sub(at_point, hit_center);
	return (vec_unit(normal));
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

t_vec	check_vec(t_obj obj)
{
	if (obj.vec.x == 0 && obj.vec.y != 0)
	{
		//printf("1\n");
		obj.vec.y = obj.vec.y * -1;
	}
	else if (obj.vec.x != 0 && obj.vec.y == 0)
	{
		//printf("2\n");
		obj.vec.x = obj.vec.x * -1;
	}
	else if (obj.vec.x != 0 && obj.vec.y != 0 && obj.vec.z == 0)
	{
		//printf("3\n");
		obj.vec.x = obj.vec.x * -1;
	}
	else if (obj.vec.x != 0 && obj.vec.y != 0 && obj.vec.z != 0)
	{
		//printf("4\n");
		obj.vec.x = obj.vec.x * -1;
		obj.vec.y = obj.vec.y * -1;
		//obj.vec.z = obj.vec.z * -1;
	}
	//printf("x:%f y:%f z:%f\n", obj.vec.x, obj.vec.y, obj.vec.z);
	return (obj.vec);
}

int	hit_cylinder_side(t_obj obj, t_ray ray, t_rec *rec)
{
	double	a;
	double	half_b;
	double	c;
	double	discriminant;
	double	root;
	//double	root1 = 0.0;
	//printf("%f\n", obj.cylin.diameter / 2);
	//printf("side x:%f y:%f z:%f\n", obj.vec.x, obj.vec.y, obj.vec.z);
	//obj.vec = check_vec(obj);
	a = length_squared(vec_cross(ray.unit_vec, obj.vec));
	half_b = vec_dot(vec_cross(ray.unit_vec, obj.vec), \
			vec_cross(vec_sub(ray.coor, obj.coor), obj.vec));
	c = length_squared(vec_cross(vec_sub(ray.coor, obj.coor), obj.vec)) \
			- pow(obj.cylin.diameter / 2, 2);
	//printf("%f %f %f\n", a, half_b, c);
	//printf("%f\n", length_squared(vec_cross(vec_sub(ray.coor, obj.coor), obj.vec)));
	//printf("%f\n", c);
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (FALSE);
	//printf("%f\n", discriminant);
	//obj.vec = check_vec(obj);
	root = (-half_b - sqrt(discriminant)) / a;
	if (rec->t_max < root || root < T_MIN)
	{
		root = (-half_b + sqrt(discriminant)) / a;
		if (root < T_MIN || rec->t_max < root)
			return (FALSE);
	}
	//printf("%f\n", root);
	//printf("%f\n", root);
/* 	if (root < root1)
		rec->t_max = root;
	else
		rec->t_max = root1; */
	if (cy_boundary(obj, ray_at(ray, root)) == FALSE)
		return (FALSE);
	rec->t_max = root;
	rec->p = ray_at(ray, root);
	rec->normal = get_normal(obj, rec->p, cy_boundary(obj, ray_at(ray, root)));
	front_face(ray, rec);
	rec->obj = obj;
	return (TRUE);
}

/*#include "miniRT.h"

static int	cy_boundary(t_obj obj, t_vec at_point)
{
	double	hit_height;
	double	max_height;

	hit_height = vec_dot(vec_sub(at_point, obj.coor), obj.vec);
	max_height = obj.cylin.height / 2;
	if (fabs(hit_height) > max_height)
		return (FALSE);
	return (TRUE);
}

static t_vec	get_normal(t_obj obj, t_vec at_point, double height)
{
	t_vec	hit_center;
	t_vec	normal;

	(void)height;
	hit_center = vec_add(obj.coor, vec_mul(obj.vec, vec_dot(vec_sub(at_point, obj.coor), obj.vec)));
	normal = vec_sub(at_point, hit_center);
	return (vec_unit(normal));
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

t_vec	check_vec(t_obj obj)
{
	if (obj.vec.x == 0 && obj.vec.y != 0)
	{
		//printf("1\n");
		obj.vec.y = obj.vec.y * -1;
	}
	else if (obj.vec.x != 0 && obj.vec.y == 0)
	{
		//printf("2\n");
		obj.vec.x = obj.vec.x * -1;
	}
	else if (obj.vec.x != 0 && obj.vec.y != 0 && obj.vec.z == 0)
	{
		//printf("3\n");
		obj.vec.x = obj.vec.x * -1;
	}
	else if (obj.vec.x != 0 && obj.vec.y != 0 && obj.vec.z != 0)
	{
		//printf("4\n");
		obj.vec.x = obj.vec.x * -1;
		obj.vec.y = obj.vec.y * -1;
		obj.vec.z = obj.vec.z * -1;
	}
	//printf("x:%f y:%f z:%f\n", obj.vec.x, obj.vec.y, obj.vec.z);
	return (obj.vec);
}

int	hit_cylinder_side(t_obj obj, t_ray ray, t_rec *rec)
{
	double	a;
	double	half_b;
	double	c;
	double	discriminant;
	double	root;

 	obj.vec = check_vec(obj);
	a = length_squared(vec_cross(ray.unit_vec, obj.vec));
	half_b = vec_dot(vec_cross(ray.unit_vec, obj.vec), \
			vec_cross(vec_sub(ray.coor, obj.coor), obj.vec));
	c = length_squared(vec_cross(vec_sub(ray.coor, obj.coor), obj.vec)) \
			- pow(obj.cylin.diameter / 2, 2);
	a = pow(vec_length(vec_cross(ray.unit_vec, obj.vec)), 2);
	half_b = vec_dot(vec_cross(ray.unit_vec, obj.vec), \
			vec_cross(vec_sub(ray.coor, obj.coor), obj.vec));
	c = pow(vec_length(vec_cross(vec_sub(ray.coor, obj.coor), obj.vec)), 2) \
			- pow(obj.cylin.diameter / 2, 2);
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (FALSE);
	obj.vec = check_vec(obj);
	root = (-half_b + sqrt(discriminant)) / a;
	if (root < T_MIN || rec->t_max < root)
	{
		root = (-half_b - sqrt(discriminant)) / a;
		if (root < T_MIN || rec->t_max < root)
			return (FALSE);
	}
	if (cy_boundary(obj, ray_at(ray, root)) == FALSE)
		return (FALSE);
	rec->t_max = root;
	rec->p = ray_at(ray, root);
	rec->normal = get_normal(obj, rec->p, cy_boundary(obj, ray_at(ray, root)));
	if (vec_dot(ray.unit_vec, rec->normal) >= 0)
		rec->normal = vec_mul(rec->normal, -1);
	front_face(ray, rec);
	rec->obj = obj;
	return (TRUE);
}
*/