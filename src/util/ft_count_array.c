int ft_count_array(char **strs)
{
	int	count;

	count = 0;
	while (strs[count])
		++count;
	return (count);
}