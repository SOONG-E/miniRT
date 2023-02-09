#include "libft.h"

static double	ft_atod2(char *str)
{
	int		i;
	double	result2;

	result2 = 0;
	i = ft_strlen(str) - 1;
	while (str[i] != '.' && (str[i] >= '0' && str[i] <= '9'))
	{
		result2 += str[i] - '0';
		result2 *= 0.1;
		i--;
	}
	return (result2);
}

double	ft_atod(char *str)
{
	int		n;
	double	result1;
	double	result2;

	n = 1;
	result1 = 0;
	result2 = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
		n *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str != '.' && (*str >= '0' && *str <= '9'))
	{
		result1 = result1 * 10 + (*str - '0');
		str++;
	}
	if (ft_strlen(str) != 0)
		result2 = ft_atod2(str);
	return (n * (result1 + result2));
}