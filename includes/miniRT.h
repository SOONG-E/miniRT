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

/* manage_resource.c */
int free_objs(t_element *objs);

/* parse_objects.c */
int parse_line(char *file_name, t_element *objs);
int recognize_object(char *object);
int count_objects(char *file_name, t_element *objs);

/* utils <directory> */
int ft_count_array(char **strs);

#endif
