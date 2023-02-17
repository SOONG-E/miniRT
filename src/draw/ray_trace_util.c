#include "miniRT.h"

double	write_color(t_vec pixel_color)
{
	return ((int)(255.999 * pixel_color.x) << 16 | (int)(255.999 * pixel_color.y) << 8 | (int)(255.999 * pixel_color.z));
}