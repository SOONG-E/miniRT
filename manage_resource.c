#include "miniRT.h"

int free_objs(t_obj *objs)
{
	return (1);
}

int	ft_free_splitted(char **chars, int len)
{
	while (0 <= --len)
		free(chars[len]);
	free(chars);
	return (1);
}