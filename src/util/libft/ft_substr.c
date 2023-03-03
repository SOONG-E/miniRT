#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	size;

	if (!s)
		return (0);
	size = ft_strlen(s);
	if (size < start)
	{
		str = malloc(1);
		if (!str)
			return (0);
		*str = 0;
		return (str);
	}
	if ((size - start) < len)
		size = size - start;
	else
		size = len;
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, s + start, size + 1);
	return (str);
}
