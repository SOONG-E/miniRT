/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_resource.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:29:00 by yujelee           #+#    #+#             */
/*   Updated: 2023/03/06 16:29:07 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ft_free_splitted(char **chars)
{
	int	i;

	i = 0;
	while (chars[i] != NULL)
		free(chars[i++]);
	free(chars);
}

void	free_resources(t_meta *meta)
{
	t_light	*head;
	t_light	*temp;

	free(meta->objs);
	head = meta->light;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
