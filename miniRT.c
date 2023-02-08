#include "miniRT.h"

int main(int ac, char **av)
{
	t_element	*objs;
	
	if (ac != 2)
		return (ft_print_error(0, "argc error"));
	if (parse_line(av[1], objs) == 1)
		return (1);
}