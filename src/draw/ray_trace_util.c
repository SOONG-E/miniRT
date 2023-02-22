#include "miniRT.h"

int	color_to_int(int t, t_vec pixel_color)
{
	return (t << 24 | (int)(255 * pixel_color.x) << 16 | (int)(255 * pixel_color.y) << 8 | (int)(255 * pixel_color.z));
}
