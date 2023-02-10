#include "miniRT.h"

int main(int ac, char **av)
{
	t_meta	meta;
	
	if (ac != 2)
		ft_exit("miniRT need only one argument");
	parse_line(av[1], &meta);

	return (0);
}