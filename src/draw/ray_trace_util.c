#include "miniRT.h"

int	write_color(double t, t_rgb pixel_color)
{
	return ((int)t << 24 | (int)(255.999 * pixel_color.r) << 16 | (int)(255.999 * pixel_color.g) << 8 | (int)(255.999 * pixel_color.b));
}