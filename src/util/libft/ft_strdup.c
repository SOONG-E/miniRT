/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:29:52 by yujelee           #+#    #+#             */
/*   Updated: 2023/03/06 16:29:53 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

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
