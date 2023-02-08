#include "libft.h"

static size_t	ft_set(char cur, char charset)
{
	if (charset == cur)
		return (1);
	return (0);
}

static size_t	ft_cnt_str(const char *str, char charset)
{
	size_t	cnt;
	size_t	i;

	cnt = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && ft_set(str[i], charset))
			i++;
		if (str[i] && ft_set(str[i], charset) == 0)
		{
			while (str[i] && ft_set(str[i], charset) == 0)
				i++;
			cnt++;
		}
	}
	return (cnt);
}

static char	**ft_free_all(char **ret, int i)
{
	while (--i >= 0)
	{
		free(ret[i]);
		ret[i] = 0;
	}
	free(ret);
	ret = 0;
	return (NULL);
}

static char	*ft_str2dup(const char *str, char charset)
{
	size_t	i;
	size_t	cnt;
	char	*temp;

	i = 0;
	cnt = 0;
	while (str[cnt] && ft_set(str[cnt], charset) == 0)
		cnt++;
	temp = (char *)malloc(sizeof(char) * cnt + 1);
	if (temp == 0)
		return (0);
	while (str[i] && ft_set(str[i], charset) == 0)
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**temp;

	i = 0;
	temp = malloc(sizeof(char *) * (ft_cnt_str(s, c) + 1));
	if (!temp)
		return (0);
	while (*s)
	{
		while (*s && ft_set(*s, c))
			s++;
		if (*s && ft_set(*s, c) == 0)
		{
			temp[i] = ft_str2dup(s, c);
			if (temp[i] == 0)
				return (ft_free_all(temp, i));
			while (*s && ft_set(*s, c) == 0)
				s++;
			i++;
		}
	}
	temp[i] = 0;
	return (temp);
}