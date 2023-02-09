#include "miniRT.h"

int main(int ac, char **av)
{
	t_meta	meta;
	
	if (ac != 2)
		return (ft_print_error(0, "miniRT need only one argument"));
	if (parse_line(av[1], &meta) == 1)
		return (1);
}