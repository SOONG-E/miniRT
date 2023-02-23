//#include "miniRT.h"

t_vec	random()
{
	return init_vec(random_double(), random_double(), random_double())
}

//정반사와 난반사 값을 더하고 주변광을 더해준다.
t_vec	phong_lightint(t_meta meta)
{
	t_vec	light_color;

	light_color = init_vec(0.1, 0.1, 0.1);
	meta.light.coor;
	meta.light.ratio;
	while ()

	light_color = vec_add(light_color, )
}