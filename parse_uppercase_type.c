#include "miniRT.h"

int parse_ambi_light(char **info, int *error_flag, t_meta *meta, int count)
{
	if (0 < meta->flag & 0x100)
		return (ft_print_error(0, "only one A in file is accepted"));
	if (count != 3)
		return (ft_print_error(0, "A need only 2 information"));
	meta->objs[0].type = A;
	meta->objs[0].ratio = ft_atoi(info[1]);
	if (meta->objs[0].ratio < 0 || 1 < meta->objs[0].ratio)
		return (ft_print_error(0, "ambient lighting ratio must in [0.0-1.0]"));
	meta->objs[0].rgb = make_rgb(info[2]);
	*error_flag = 0;
	return (0);
}

void parse_camera(char **info, int *error_flag, t_meta *meta)
{
	

}

void parse_light(char **info, int *error_flag, t_meta *meta)
{
	
}
