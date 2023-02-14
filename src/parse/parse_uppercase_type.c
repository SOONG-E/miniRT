#include "miniRT.h"
#include <stdio.h>

void parse_ambi_light(char **info, t_meta *meta)
{
	check_available(meta, A);
	meta->ambi.ratio = put_double(info[1], 0.0, 1.0);
	meta->ambi.rgb = make_rgb(info[2]);
	meta->flag |= 0b100;
}

void parse_camera(char **info, t_meta *meta)
{
	check_available(meta, C);
	meta->cam.coor = make_coor(info[1], 0, 0);
	meta->cam.vec = make_coor(info[2], -1, 1);
	meta->cam.fov = (int)put_double(info[3], 0, 180);
	meta->flag |= 0b10;
}

void parse_light(char **info, t_meta *meta)
{
	check_available(meta, L);
	meta->light.coor = make_coor(info[1], 0, 0);
	meta->light.ratio = put_double(info[2], 0.0, 1.0);
	meta->flag |= 0b1;
}
