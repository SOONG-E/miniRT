#include "miniRT.h"

double	degree_to_radian(double degree)
{
	return (degree * M_PI / 180.0);
}

t_vec	get_rotate_dir(int key)
{
	if (key == KEY_ARROW_UP)
		return (init_vec(0, 0, -1));
	else if (key == KEY_ARROW_DOWN)
		return (init_vec(0, 0, 1));
	else if (key == KEY_ARROW_LEFT)
		return (init_vec(0, 1, 0));
	else if (key == KEY_ARROW_RIGHT)
		return (init_vec(0, -1, 0));
	else if (key == KEY_SHIFT)
		return (init_vec(1, 0, 0));
	else if (key == KEY_CTRL)
		return (init_vec(-1, 0, 0));
	return (init_vec(0, 0, 0));
}

void	rotation_matrix(t_vec axis, double angle, double matrix[3][3])
{
	const double	c = cos(angle);
	const double	s = sin(angle);
	const double	t = 1.0 - c;

	matrix[0][0] = t * axis.x * axis.x + c;
	matrix[0][1] = t * axis.x * axis.y - s * axis.z;
	matrix[0][2] = t * axis.x * axis.z + s * axis.y;
	matrix[1][0] = t * axis.x * axis.y + s * axis.z;
	matrix[1][1] = t * axis.y * axis.y + c;
	matrix[1][2] = t * axis.y * axis.z - s * axis.x;
	matrix[2][0] = t * axis.x * axis.z - s * axis.y;
	matrix[2][1] = t * axis.y * axis.z + s * axis.x;
	matrix[2][2] = t * axis.z * axis.z + c;
}

t_vec	apply_rotation_matrix(t_vec vector, double matrix[3][3])
{
	t_vec	result;

	result.x = matrix[0][0] * vector.x + matrix[0][1] * \
		vector.y + matrix[0][2] * vector.z;
	result.y = matrix[1][0] * vector.x + matrix[1][1] * \
		vector.y + matrix[1][2] * vector.z;
	result.z = matrix[2][0] * vector.x + matrix[2][1] * \
		vector.y + matrix[2][2] * vector.z;
	return (result);
}
