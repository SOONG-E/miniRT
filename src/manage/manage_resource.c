#include "miniRT.h"

void	ft_free_splitted(char **chars)
{
	int	i;

	i = 0;
	while (chars[i] != NULL)
		free(chars[i++]);
	free(chars);
}