#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

void	*ft_calloc(size_t count, size_t elt_size);
char	**ft_split(char *str, char *charset);
char	*ft_strdup(const char *str);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atoi(const char *str);
double	ft_atod(char *str);

#endif