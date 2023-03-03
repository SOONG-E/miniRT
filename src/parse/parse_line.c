#include "miniRT.h"

static void	recognize_object(char **info, t_meta *meta)
{
	int	count;

	if (info == NULL)
		ft_exit("system function fail");
	count = ft_count_array(info);
	if (ft_strcmp(info[0], "A") == 0 && check_num_info(count, 3) == 0)
		parse_ambi_light(info, meta);
	else if (ft_strcmp(info[0], "C") == 0 && check_num_info(count, 4) == 0)
		parse_camera(info, meta);
	else if (ft_strcmp(info[0], "L") == 0)
		parse_light(info, meta, count);
	else if (ft_strcmp(info[0], "sp") == 0 && check_num_info(count, 4) == 0)
		parse_sphere(info, meta);
	else if (ft_strcmp(info[0], "pl") == 0 && check_num_info(count, 4) == 0)
		parse_plane(info, meta);
	else if (ft_strcmp(info[0], "cy") == 0 && check_num_info(count, 6) == 0)
		parse_cylinder(info, meta);
	else
		ft_exit("invalid type in file");
	ft_free_splitted(info);
}

static void	create_meta(char *file_name, t_meta *meta)
{
	meta->obj_num = count_objects(file_name) - 3;
	if (meta->obj_num < 0)
		ft_exit("lack of objects");
	meta->objs = (t_obj *)ft_calloc(meta->obj_num, sizeof(t_obj));
	if (meta->objs == NULL)
		ft_exit("system function fail");
	meta->flag = 0;
	meta->mode = -1;
	meta->light = NULL;
	meta->hits[SP] = hit_sphere;
	meta->hits[PL] = hit_plane;
	meta->hits[CY] = hit_cylinder;
	window_init(&(meta->mlx));
}

static void	fill_objs(char *file_name, t_meta *meta)
{
	int		fd;
	char	*temp;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		ft_exit("file open error");
	temp = get_next_line(fd);
	while (temp)
	{
		if (1 < ft_strlen(temp) && temp[0] != '#')
			recognize_object(ft_split(temp, "\n "), meta);
		free(temp);
		temp = get_next_line(fd);
	}
	if ((meta->flag & 0b111) != 0b111)
		ft_exit("A, C, L must exist once");
	free(temp);
}

void	parse_line(char *file_name, t_meta *meta)
{
	check_file_name(file_name);
	create_meta(file_name, meta);
	fill_objs(file_name, meta);
}
