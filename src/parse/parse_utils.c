#include "miniRT.h"

void	check_file_name(char *file_name)
{
	int	len;

	len = ft_strlen(file_name);
	if (len < 3)
		ft_exit("miniRT need exist \".rt\" file.");
	if (ft_strcmp(&file_name[len - 3], ".rt") != 0)
		ft_exit("miniRT need exist \".rt\" file.");
}

int count_objects(char *file_name)
{
	int		fd;
	char	*temp;
	int		count;

	count = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		ft_exit("file open error");
	temp = get_next_line(fd);
	while (temp)
	{
		if (ft_strlen(temp) > 1)
			++count;
		free(temp);
		temp = get_next_line(fd);
	}
	free(temp);
	close(fd);
	return (count);
}

void	check_available(t_meta *meta, t_type type)
{
	if (type == A && 0 < (meta->flag & 0x100))
		ft_exit("couldn't apply A type more than one");
	else if (type == C && 0 < (meta->flag & 0x10))
		ft_exit("couldn't apply C type more than one");
	else if (type == L && 0 < (meta->flag & 0x1))
		ft_exit("couldn't apply L type more than one");
}

int	check_num_info(int count, int stand)
{
	if (count != stand)
		ft_exit("check num of information");
	return (0);
}