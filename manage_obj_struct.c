#include "miniRT.h"

t_coor	make_coor(char *info)
{
	t_coor	ret;
	char	**nums;

	nums = ft_split(info, ",");
	if (ft_count_array(nums) != 3)
		//error handling
	ret.x = ft_atod(nums[0]);
	ret.y = ft_atod(nums[1]);
	ret.z = ft_atod(nums[2]);
	ft_free_splitted(nums, 3);
	return (ret);
}

t_rgb	make_rgb(char *info)
{
	t_rgb	ret;
	char	**nums;

	nums = ft_split(info, ",");
	if (ft_count_array(nums) != 3)
		//error handling
	ret.r = ft_atoi(nums[0]);
	ret.g = ft_atoi(nums[1]);
	ret.b = ft_atoi(nums[2]);
	if (ret.r | 0x111 != 0x111 || ret.g | 0x111 != 0x111 
	|| ret.b | 0x111 != 0x111)
		//error handling
	ft_free_splitted(nums, 3);
	return (ret);
}

t_cylin	make_cylin(char *info)
{
	t_cylin	ret;
	char	**nums;

	nums = ft_split(info, ",");
	if (ft_count_array(nums) != 2)
		//error handling
	ret.diameter = ft_atod(nums[0]);
	ret.height = ft_atod(nums[1]);
	ft_free_splitted(nums, 2);
	return (ret);
}