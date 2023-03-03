#include "miniRT.h"

t_vec	vec_unit(t_vec v)
{
	double	len;

	if (v.x == 0 && v.y == 0 && v.z == 0)
		printf("0 vector error\n");
	len = vec_length(v);
	return (init_vec(v.x / len, v.y / len, v.z / len));
}

double	vec_length(t_vec v1)
{
	return (sqrt(length_squared(v1)));
}

t_vec	vec_cal(t_vec *v, double *a, int n)
{
	t_vec	out;

	out = init_vec(0, 0, 0);
	while (n--)
	{
		out.x += v[n].x * a[n];
		out.y += v[n].y * a[n];
		out.z += v[n].z * a[n];
	}
	return (out);
}

double	vec_dot(t_vec v1, t_vec v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vec	vec_cross(t_vec v1, t_vec v2)
{
	t_vec	out;

	out.x = v1.y * v2.z + v1.z * v2.y;
	out.y = v1.z * v2.x + v1.x * v2.z;
	out.z = v1.x * v2.y + v1.y * v2.x;
	return (out);
}
