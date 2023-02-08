#include "miniRT.h"

int count_objects(char *file_name, t_element *objs)
{
	int		fd;
	char	*temp;
	int		count;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (ft_print_error(0, "file open error"));
	temp = get_next_line(fd);
	while (temp)
	{
		if (ft_strlen(temp) > 0)
			++count;
		temp = get_next_line(fd);
	}
	close(fd);
	objs = (t_element *)ft_calloc(count, sizeof(t_element));
	if (objs == NULL)
		return (ft_print_error(0, "system function fail"));
	return (0);
}

int recognize_object(char **info)
{
	// int	count;
	// int error_flag;

	// count = ft_count_array(info);
	// if (count == 3 && ft_strcmp(info[0], "A") == 0)
	// 	parse_ambient_lightning(info, &error_flag);
	// else if (count == 4)
	// {
	// 	if (ft_strcmp(info[0], "C") == 0)
	// 		parse_camera(info, &error_flag);
	// 	else if (ft_strcmp(info[0], "L") == 0)
	// 		parse_light(info, &error_flag);
	// 	else if (ft_strcmp(info[0], "sp") == 0)
	// 		parse_sphere(info, &error_flag);
	// 	else if (ft_strcmp(info[0], "pl") == 0)
	// 		parse_plane(info, &error_flag);
	// 	else
	// 		return (ft_print_error(0, "invalid type"));
	// }
	// else if (count == 5 && ft_strcmp(info[0], "cy") == 0)
	// 	parse_cylinder(info, &error_flag);
	// else
	// 	return (ft_print_error(0, "invalid type"));
	// return (0);
}

int parse_line(char *file_name, t_element *objs)
{
	int		fd;
	char	*temp;

	if (count_objects(file_name, objs) == 1)
		return (1);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (ft_print_error(0, "file open error"));
	temp = get_next_line(fd);
	while (temp)
	{
		if (ft_strlen(temp) > 0 && recognize_object(ft_split(temp, " ")) == 1)
			return (free_objs(objs));
		free(temp);
		temp = get_next_line(fd);
	}
	free(temp);
	return (0);
}