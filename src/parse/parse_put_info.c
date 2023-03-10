#include "miniRT.h"

double	put_double(char *str, double min, double max)
{
	double	ret;

	ret = ft_atod(str);
	if (min != max && (ret < min || max < ret))
		ft_exit("info is out of range!");
	return (ret);
}

t_vec	make_coor(char *info, double min, double max)
{
	t_vec	ret;
	char	**nums;

	nums = ft_split(info, ",");
	if (ft_count_array(nums) != 3)
		ft_exit("coordination need only three information");
	ret.x = put_double(nums[0], min, max);
	ret.y = put_double(nums[1], min, max);
	ret.z = put_double(nums[2], min, max);
	ft_free_splitted(nums);
	return (ret);
}

t_vec	make_vec(char *info, double min, double max)
{
	t_vec	ret;

	ret = make_coor(info, min, max);
	ret = vec_unit(ret);
	return (ret);
}

t_vec	make_rgb(char *info)
{
	t_vec	ret;
	char	**nums;

	nums = ft_split(info, ",");
	if (ft_count_array(nums) != 3)
		ft_exit("rgb need only three information");
	ret.x = put_double(nums[0], 0, 255);
	ret.y = put_double(nums[1], 0, 255);
	ret.z = put_double(nums[2], 0, 255);
	if (((int)ret.x | 255) != 255 || ((int)ret.y | 255) != 255
		|| ((int)ret.z | 255) != 255)
		ft_exit("rgb is out of range!");
	ret.x /= 255.0;
	ret.y /= 255.0;
	ret.z /= 255.0;
	ft_free_splitted(nums);
	return (ret);
}

t_cylin	make_cylin(char *diameter, char *height)
{
	t_cylin	ret;

	ret.diameter = ft_atod(diameter);
	ret.height = ft_atod(height);
	return (ret);
}
