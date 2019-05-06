/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbackaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:23:52 by qbackaer          #+#    #+#             */
/*   Updated: 2019/05/06 18:00:34 by qbackaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		smallest_sq(t_tetra *head)
{
	t_tetra	*roam;
	int		count;
	int		edge_sz;

	if (!head)
		return (0);
	roam = head;
	count = 0;
	while (roam)
	{
		count++;
		roam = roam->next;
	}
	edge_sz = 2;
	while (edge_sz *edge_sz < (count *4))
		edge_sz++;
	return (edge_sz);
}

t_tetra	*add_node(t_tetra *head, char *buff)
{
	t_tetra *new_node;
	t_tetra	*roam;

	if (!(new_node = malloc(sizeof(t_tetra))))
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

t_tetra	*coord(char *str, t_tetra *node)
{
	int	i;
	int	j;

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

t_tetra	*tetra_id(t_tetra *head)
{
	t_tetra	*roam;
	int		i;

	if (!head)
		return (NULL);
	roam = head;
	i = 0;
	while (roam)
	{
		roam->id = ('A' + i);
		i++;
		roam = roam->next;
	}
	return (head);
}

void	read_list(t_tetra *head)
{
	int		i;
	t_tetra	*roam;

	if (!head)
		printf("decapitated!\n");
	roam = head;
	while (roam)
	{
		i = 0;
		printf("===========\n\n");
		while (i < 4)
		{
			printf(" - id: %c\n", roam->id);
			printf(" - x(%d): %d\n", i, roam->x[i]);
			printf(" - y(%d): %d\n\n", i, roam->y[i]);
			i++;
		}
		printf("===========\n\n");
		roam = roam->next;
	}
}
