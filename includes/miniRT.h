#ifndef MINIRT_H
# define MINIRT_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mlx.h>
#include <fcntl.h>
#include "structs.h"
#include "get_next_line.h"
#include "libft.h"

/* manage_error.c */
int ft_print_error(int code, char *msg);
void *ft_print_error_null(int code, char *msg);

/* manage_resource.c */
int free_objs(t_obj *objs);
int	ft_free_splitted(char **chars, int len);

/* parse_objects.c */
int parse_line(char *file_name, t_obj *objs);
int recognize_object(char **info);

/* parse_utils.c */
int	check_file_name(char *file_name);
int count_objects(char *file_name);

/* manage_obj_struct.c */
t_coor	make_coor(char *info);
t_rgb	make_rgb(char *info);
t_cylin	make_cylin(char *info);

/* utils <directory> */
int ft_count_array(char **strs);

#endif
