#include "miniRT.h"

double	put_double(char *str, double min, double max)
{
	double	ret;

	ret = ft_atod(str);
	if (min != max && (ret < min || max < ret))
		ft_exit("info is out of range!");
	return (ret);
}

t_coor	make_coor(char *info, double min, double max)
{
	t_coor	ret;
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

t_coor	make_vec(char *info, double	min, double max)
{
	t_coor	ret;
	double	distance;

	ret = make_coor(info, min, max);
	distance = sqrt(pow(ret.x, 2) + pow(ret.y, 2) + pow(ret.z, 2));
	ret.x /= distance;
	ret.y /= distance;
	ret.z /= distance;
	return (ret);
}

t_rgb	make_rgb(char *info)
{
	t_rgb	ret;
	char	**nums;

	nums = ft_split(info, ",");
	if (ft_count_array(nums) != 3)
		ft_exit("rgb need only three information");
	ret.r = ft_atoi(nums[0]);
	ret.g = ft_atoi(nums[1]);
	ret.b = ft_atoi(nums[2]);
	if ((ret.r | 255) != 255 || (ret.g | 255) != 255
	|| (ret.b | 255) != 255)
		ft_exit("rgb is out of range!");
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
