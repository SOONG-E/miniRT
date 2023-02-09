#include "miniRT.h"

int	check_file_name(char *file_name)
{
	int	len;

	len = ft_strlen(file_name);
	if (len < 3)
		return (ft_print_error(0, "miniRT need exist \".rt\" file."));
	if (ft_strcmp(&file_name[len - 3], ".rt") != 0)
		return (ft_print_error(0, "miniRT need exist \".rt\" file."));
	return (0);
}

int count_objects(char *file_name)
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
	return (count);
}