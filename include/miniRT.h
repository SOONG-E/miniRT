#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <mlx.h>
# include <fcntl.h>
# include "structs.h"
# include "get_next_line.h"
# include "libft.h"

/* manage_error.c */
void	ft_exit(char *errmsg);

/* manage_resource.c */
void	ft_free_splitted(char **chars);

/* parse_line.c */
void	parse_line(char *file_name, t_meta *meta);

/* parse_lowercase_type.c */
void parse_sphere(char **info, t_meta *meta);
void parse_plane(char **info, t_meta *meta);
void parse_cylinder(char **info, t_meta *meta);

/* parse_uppercase_type.c */
void parse_ambi_light(char **info, t_meta *meta);
void parse_camera(char **info, t_meta *meta);
void parse_light(char **info, t_meta *meta);

/* parse_utils.c */
void	check_file_name(char *file_name);
int		count_objects(char *file_name);
void	check_available(t_meta *meta, t_type type);
int		check_num_info(int count, int stand);

/* parse_put_info.c */
double	put_double(char *str, double min, double max);
t_coor	make_coor(char *info, double min, double max);
t_rgb	make_rgb(char *info);
t_cylin	make_cylin(char *diameter, char *height);
int	get_index(t_meta *meta);

/* utils <directory> */
int		ft_count_array(char **strs);

#endif
