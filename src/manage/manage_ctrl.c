#include "miniRT.h"

static void	select_light(t_meta *meta)
{
	meta->ctrl.light = meta->ctrl.light->next;
	if (meta->ctrl.light == NULL)
		meta->ctrl.light = meta->light;
}

static void	select_object(t_meta *meta)
{
	int	idx;

	idx = meta->ctrl.obj->num + 1;
	if (idx == meta->obj_num)
		idx = 0;
	meta->ctrl.obj = &(meta->objs[idx]);
}

void	select_obj(t_meta *meta)
{
	if (meta->ctrl.category == KEY_L)
		select_light(meta);
	else if (meta->ctrl.category == KEY_O)
		select_object(meta);
}

void	set_category(int key, t_meta *meta)
{
	if (key == KEY_L)
	{
		meta->ctrl.category = KEY_L;
		meta->ctrl.light = meta->light;
	}
	else if (key == KEY_C)
		meta->ctrl.category = KEY_C;
	else if (key == KEY_O)
	{
		meta->ctrl.category = KEY_O;
		meta->ctrl.obj = &(meta->objs[0]);
	}
}
