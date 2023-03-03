#include "miniRT.h"

t_vec	reflect(t_vec v1, t_vec v2)
{
	double	ray_light_dot;
	t_vec	ray_vec_dot;
	t_vec	reverse_vec;

	ray_light_dot = vec_dot(v1, v2);
	ray_vec_dot = vec_mul(v2, ray_light_dot * 2);
	reverse_vec = vec_mul(v1, -1);
	return (vec_add(reverse_vec, ray_vec_dot));
}

t_vec	point_light_get(t_meta meta, t_ray ray, t_light *light)
{
	t_vec	diffuse;
	t_vec	light_dir;
	t_ray	light_ray;
	double	kd;

	light_dir = vec_sub(light->coor, ray.rec.p);
	light_ray = init_ray(vec_add(ray.rec.p, vec_mul(ray.rec.normal, T_MIN)), light_dir);
	if (in_shadow(meta, light_ray, vec_length(light_dir)) == TRUE)
		return (init_vec(0, 0, 0));
	light_dir = vec_unit(light_dir);
	kd = fmax(vec_dot(ray.rec.normal, light_dir), 0.0);
	diffuse = vec_mul(light->color, kd);

	return (diffuse);
}

t_vec	get_specular(t_ray ray, t_light *light)
{
	t_vec	view_dir;
	t_vec	reflect_dir;
	t_vec	light_dir;
	double	spec;

	light_dir = vec_unit(vec_sub(light->coor, ray.rec.p));
	view_dir = vec_unit(vec_mul(ray.unit_vec, -1));
	reflect_dir = reflect(light_dir, ray.rec.normal);
	spec = pow(fmax(vec_dot(view_dir, reflect_dir), 0.0), 50);
	return (vec_mul(vec_mul(light->color, 0.9), spec));
}

t_vec	phong_lighting(t_meta meta, t_ray ray)
{
	t_vec	light_color;
	t_light	*light;

	light_color = init_vec(0, 0, 0);
	light = meta.light;
	while (light)
	{
		light_color = vec_add(light_color, point_light_get(meta, ray, light));
		light_color = vec_add(light_color, get_specular(ray, light));
		light = light->next;
	}
	light_color = vec_add(light_color, meta.ambi.rgb);
	return (vec_min(vecs_mul(light_color, ray.rec.obj.rgb), init_vec(1, 1, 1)));
}
