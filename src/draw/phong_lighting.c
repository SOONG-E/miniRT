#include "miniRT.h"

// t_vec	reflect(t_vec v1, t_vec v2)
// {
// 	double	ray_light_dot;
// 	t_vec	ray_vec_dot;
// 	t_vec	reverse_vec;

// 	ray_light_dot = vec_dot(v1, v2);
// 	ray_vec_dot = vec_mul(v2, ray_light_dot * 2);
// 	reverse_vec = vec_mul(v1, -1);
// 	return (vec_add(reverse_vec, ray_vec_dot));
// }

// t_vec	point_light_get(t_meta meta, t_ray ray, t_vec light_color)
// {
// 	t_vec	vec_light;
// 	t_vec	view_dir;
// 	t_vec	specular;
// 	double	kd;
// 	double	spec;

// 	vec_light = vec_unit(vec_sub(meta.light.coor, ray.obj_draw.p));
// 	kd = fmax(vec_dot(ray.obj_draw.normal, vec_light), 0.0);
// 	view_dir = vec_unit(vec_mul(ray.unit_vec, -1));
// 	spec = pow(fmax(vec_dot(view_dir, reflect(ray.unit_vec, ray.obj_draw.normal)), 0.0), 30);
// 	specular = vec_mul(vec_mul(light_color, 0.8), spec);
// 	return (vec_add(vec_mul(light_color, kd), specular));
// }

t_vec	vec_scal_add(t_vec v, double d)
{
	v.x += d;
	v.y += d;
	v.z += d;
	return (v);
}

t_vec	point_light_get(t_ray ray, t_light light)
{
	t_vec	diffuse;
	t_vec	light_dir;
	double	kd;

	light_dir = vec_unit(vec_sub(light.coor, ray.obj_draw.p));
	kd = fmax(vec_dot(ray.obj_draw.normal, light_dir), 0.0);
	diffuse = vec_mul(init_vec(1, 1, 1), kd);

	return (diffuse);
}

// 정반사와 난반사 값을 더하고 주변광을 더해준다.
t_vec	phong_lighting(t_meta meta, t_ray ray)
{
	t_vec	light_color;

	light_color = init_vec(0, 0, 0);
	
	light_color = vec_add(light_color, point_light_get(ray, meta.light));
	// light_color = vec_mul(init_vec(1,1,1), meta.light.ratio);
	// light_color = vec_add(light_color, point_light_get(meta, ray, light_color));
	light_color = vec_add(light_color, vec_mul(meta.ambi.rgb, meta.ambi.ratio));
	return (vec_min(vecs_mul(light_color, ray.obj_draw.albedo), init_vec(1, 1, 1)));
}
