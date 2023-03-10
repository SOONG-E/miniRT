#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include "structs.h"
# include "get_next_line.h"
# include "libft.h"

# define WIDTH				800
# define HEIGHT				450

# define KEY_ESC			53
# define KEY_ARROW_LEFT		123
# define KEY_ARROW_RIGHT	124
# define KEY_ARROW_DOWN		125
# define KEY_ARROW_UP		126
# define KEY_D				2
# define KEY_Z				6
# define KEY_C				8
# define KEY_O				31
# define KEY_L				37
# define KEY_M				46
# define KEY_TAB			48
# define KEY_SHIFT			257
# define KEY_CTRL			256

# define TRUE	0
# define FALSE	1

# define T_MIN	1e-6

/*************/
/*	draw	*/
/************/

/* check_hit_cylinder.c */
int		hit_cylinder_cap(t_obj obj, t_ray ray, t_rec *rec, double height);
int		hit_cylinder_side(t_obj obj, t_ray ray, t_rec *rec);

/* check_is_hit.c */
void	front_face(t_ray ray, t_rec *rec);
int		hit_sphere(t_obj obj, t_ray ray, t_rec *rec);
int		hit_plane(t_obj obj, t_ray ray, t_rec *rec);
int		hit_cylinder(t_obj obj, t_ray ray, t_rec *rec);
int		is_hit(t_meta meta, t_ray ray, t_rec *rec);

/* phong_lighting.c */
t_vec	phong_lighting(t_meta meta, t_ray ray);

/* ray_trace.c */
void	ray_trace(t_meta *meta);

/* ray_trace_util.c */
t_vec	clamp(t_vec v, double min, double max);
int		color_to_int(int t, t_vec pixel_color);
t_vec	vec_min(t_vec a, t_vec b);
t_vec	ray_at(t_ray ray, double t);
t_vec	get_lowerleft_corner(t_vec origin, t_bg bg, t_vec w);

/* check_hit_cylinder.c */
int		hit_cylinder_cap(t_obj obj, t_ray ray, t_rec *rec, double height);
int		hit_cylinder_side(t_obj obj, t_ray ray, t_rec *rec);

/* draw_shadow.c */
int		in_shadow(t_meta meta, t_ray light_ray, double light_len);

/*************/
/*	vec		*/
/************/

/* calculate_basic_vec.c */
t_vec	vec_add(t_vec v1, t_vec v2);
t_vec	vec_sub(t_vec v1, t_vec v2);
t_vec	vec_mul(t_vec v1, double t);
t_vec	vec_div(t_vec v1, double t);
t_vec	vecs_mul(t_vec v1, t_vec v2);

/* calculate_vec.c */
t_vec	vec_unit(t_vec v);
double	vec_length(t_vec v1);
t_vec	vec_cal(t_vec *v, double *a, int n);
t_vec	vec_cross(t_vec v1, t_vec v2);
double	vec_dot(t_vec v1, t_vec v2);

/* calculate_util.c */
double	length_squared(t_vec v1);

/* init_vec.c */
t_vec	init_vec(double x, double y, double z);
t_ray	init_ray(t_vec coor, t_vec	unit_vec);
t_rec	init_rec(void);

/* rotate_vec.c */
double	degree_to_radian(double degree);
t_vec	get_rotate_dir(int key);
void	rotation_matrix(t_vec axis, double angle, double matrix[3][3]);
t_vec	apply_rotation_matrix(t_vec vector, double matrix[3][3]);


/*************/
/*	manage	*/
/************/

/* manage_controller.c */
void	control_obj(int key, t_meta *meta, int *flag);

/* manage_ctrl.c */
void	select_obj(t_meta *meta);
void	set_category(int key, t_meta *meta);

/* manage_error.c */
void	ft_exit(char *errmsg);

/* manage_resource.c */
void	ft_free_splitted(char **chars);
void	free_resources(t_meta *meta);

/* manage_keyhook.c */
int		key_event(int key, t_meta *meta);
int		exit_hook(t_meta *meta);
int		binding_key_events(int key, t_meta *meta);

/* manage_mlx.c */
void	put_color(t_mlx *mlx, int x, int y, int color);
void	open_screen(t_mlx *mlx, t_meta *meta);
void	window_init(t_mlx *mlx);

/*************/
/*	parse	*/
/************/

/* parse_line.c */
void	parse_line(char *file_name, t_meta *meta);

/* parse_lowercase_type.c */
void	parse_sphere(char **info, t_meta *meta);
void	parse_plane(char **info, t_meta *meta);
void	parse_cylinder(char **info, t_meta *meta);

/* parse_uppercase_type.c */
void	parse_ambi_light(char **info, t_meta *meta);
void	parse_camera(char **info, t_meta *meta);
void	parse_light(char **info, t_meta *meta, int count);

/* parse_utils.c */
void	check_file_name(char *file_name);
int		count_objects(char *file_name);
void	check_available(t_meta *meta, t_type type);
int		check_num_info(int count, int stand);
int		get_index(t_meta *meta);

/* parse_put_info.c */
double	put_double(char *str, double min, double max);
t_vec	make_coor(char *info, double min, double max);
t_vec	make_vec(char *info, double min, double max);
t_vec	make_rgb(char *info);
t_cylin	make_cylin(char *diameter, char *height);

/*************/
/*	util	*/
/************/

int		ft_count_array(char **strs);

#endif
