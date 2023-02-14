#include "libft.h"

int	ft_set(char cur, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == cur)
			return (1);
		i++;
	}
	return (0);
}

int	ft_cnt_str(char *str, char *charset)
{
	int	cnt;
	int	i;

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

char	*ft_strdup_02(char *str, char *charset)
{
	int		i;
	char	*temp;
	int		cnt;

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

char	**ft_split(char *str, char *charset)
{
	int		i;
	char	**temp;

	i = 0;
	temp = (char **)malloc(sizeof(char *) * (ft_cnt_str(str, charset) + 1));
	if (temp == 0)
		return (0);
	while (*str)
	{
		while (*str && ft_set(*str, charset))
			str++;
		if (*str && ft_set(*str, charset) == 0)
		{
			temp[i] = ft_strdup_02(str, charset);
			while (*str && ft_set(*str, charset) == 0)
				str++;
			i++;
		}
	}
	temp[i] = 0;
	return (temp);
}
