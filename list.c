/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbackaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:23:52 by qbackaer          #+#    #+#             */
/*   Updated: 2019/04/25 17:42:56 by qbackaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_tetra		*add_node(t_tetra *head, char *buff)
{
	t_tetra *new_node;
	t_tetra	*roam;

	if (!(new_node = malloc(sizeof(new_node))))
		return (NULL);	
	new_node = coord(buff, new_node);
	new_node->next = NULL;
	if (!head)
	{
		head = new_node;
		return (head);
	}
	roam = head;
	while (roam->next)
		roam = roam->next;
	roam->next = new_node;
	return (head);
}

t_tetra     *coord(char *str, t_tetra *node)
{
	int             i;
	int             j

	i = 0;
	j = 0;
	while (str[i] && j < 4)
	{
		if (str[i] == '#')
		{
			node->x[j] = i % 5;
			node->y[j] = i / 5;
			j++;
		}
		i++;
	}
	return (node);
}
