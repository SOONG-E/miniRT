#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		len;
	char	*dest;

	len = ft_strlen(str);
	dest = malloc((sizeof(char)) * (len + 1));
	if (!dest)
		return (0);
	ft_strlcpy(dest, str, len + 1);
	return (dest);
}
