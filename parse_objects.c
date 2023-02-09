#include "miniRT.h"


int recognize_object(char **info, t_meta *meta)
{
	int error_flag;
	int	count;

	error_flag = 1;
	count = ft_count_array(info);
	if (info == NULL)
		return (ft_print_error(1, NULL));
	if (ft_strcmp(info[0], "A") == 0)
		parse_ambient_lightning(info, &error_flag, meta, count);
	else if (ft_strcmp(info[0], "C") == 0)
		parse_camera(info, &error_flag, meta, count);
	else if (ft_strcmp(info[0], "L") == 0)
		parse_light(info, &error_flag, meta, count);
	else if (ft_strcmp(info[0], "sp") == 0)
		parse_sphere(info, &error_flag, meta, count);
	else if (ft_strcmp(info[0], "pl") == 0)
		parse_plane(info, &error_flag, meta, count);
	else if (ft_strcmp(info[0], "cy") == 0)
		parse_cylinder(info, &error_flag, meta, count);
	else
		return (ft_print_error(0, "invalid type"));
	if (error_flag == 1)
		return (1);
	return (0);
}

int create_objs(char *file_name, t_meta *meta)
{
	if (check_file_name(file_name) == 1)
		return (1);
	meta->obj_num = count_objects(file_name);
	if (meta->obj_num == 1)
		return (1);
	if (meta->obj_num < 3)
		return (ft_print_error(0, "lack of objects"));
	meta->objs = (t_obj *)ft_calloc(meta->obj_num, sizeof(t_obj));
	if (meta->objs == NULL)
		return (ft_print_error(1, NULL));
	meta->flag = 0;
	return (0);
}

int	parse_line(char *file_name, t_meta *meta)
{
	int		fd;
	char	*temp;

	if (create_objs(file_name, meta) == 1)
		return (1);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (ft_print_error(0, "file open error"));
	temp = get_next_line(fd);
	while (temp)
	{
		if (ft_strlen(temp) > 0 
		&& recognize_object(ft_split(temp, " "), meta) == 1)
			return (free_objs(meta->objs));
		free(temp);
		temp = get_next_line(fd);
	}
	free(temp);
	return (0);
}