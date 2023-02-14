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
# include "ray_trace.h"

# define	WIDTH	800
# define	HEIGHT	WIDTH / 16 / 9
# define	KEY_ESC	53

/*************/
/*	draw	*/
/************/

void	ray_tracing(t_meta meta);
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
int		key_event(int key, t_mlx *mlx);
int		exit_hook(void);
void	window_init(t_mlx *mlx);



/* ray_trace_util.c */
t_vec	init_vec(double x, double y, double z);
double	write_color(t_vec *pixel_color);

/*************/
/*	vec		*/
/************/

/* calculate_basic_vec.c */
t_vec	vec_add(t_vec v1, t_vec v2);
t_vec 	vec_sub(t_vec v1, t_vec v2);
t_vec	vec_mul(t_vec v1, double t);
t_vec	vec_div(t_vec v1, double t);

/* calculate_vec.c */
t_vec	vec_unit(t_vec v);
double	vec_length(t_vec v1);
t_vec	vec_cal(t_vec v, double *a, int n);
t_vec	vec_cross(t_vec v1, t_vec v2);
double	vec_dot(t_vec v1, t_vec v2);

/* calculate_util.c */
double	length_squared(t_vec v1);

/* init_vec.c */
t_vec	init_vec(double x, double y, double z);

/*************/
/*	manage	*/
/************/

/* manage_error.c */
void	ft_exit(char *errmsg);

/* manage_resource.c */
void	ft_free_splitted(char **chars);

/* manage_keyhook.c */
int		key_event(int key, t_mlx *mlx);
int		exit_hook(void);

/* manage_mlx.c */
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
void	window_init(t_mlx *mlx);

/*************/
/*	parse	*/
/************/

/* parse_line.c */
void	parse_line(char *file_name, t_meta *meta);

/* parse_lowercase_type.c */
void 	parse_sphere(char **info, t_meta *meta);
void 	parse_plane(char **info, t_meta *meta);
void 	parse_cylinder(char **info, t_meta *meta);

/* parse_uppercase_type.c */
void 	parse_ambi_light(char **info, t_meta *meta);
void 	parse_camera(char **info, t_meta *meta);
void 	parse_light(char **info, t_meta *meta);

/* parse_utils.c */
void	check_file_name(char *file_name);
int		count_objects(char *file_name);
void	check_available(t_meta *meta, t_type type);
int		check_num_info(int count, int stand);
int		get_index(t_meta *meta);

/* parse_put_info.c */
double	put_double(char *str, double min, double max);
t_vec	make_coor(char *info, double min, double max);
t_vec	make_vec(char *info, double	min, double max);
t_rgb	make_rgb(char *info);
t_cylin	make_cylin(char *diameter, char *height);

/*************/
/*	util	*/
/************/

int		ft_count_array(char **strs);

#endif
