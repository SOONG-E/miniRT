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
