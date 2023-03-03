#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	unsigned char	uc;
	size_t			i;

	ptr = (unsigned char *)b;
	uc = (unsigned char)c;
	i = 0;
	while (i++ < len)
		*ptr++ = uc;
	return (b);
}

void	*ft_calloc(size_t count, size_t elt_size)
{
	void	*arr;

	arr = malloc(count * elt_size);
	if (arr == 0)
		return (0);
	ft_memset(arr, 0, elt_size * count);
	return (arr);
}
