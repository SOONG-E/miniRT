/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:29:34 by yujelee           #+#    #+#             */
/*   Updated: 2023/03/06 16:29:35 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_array(char **strs)
{
	int	count;

	count = 0;
	while (strs[count])
		++count;
	return (count);
}
