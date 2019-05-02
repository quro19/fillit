/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 18:54:31 by srobin            #+#    #+#             */
/*   Updated: 2019/05/02 20:12:19 by srobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetra	*tetra_placement_x(t_tetra *head)
{
	int		i;
	int		j;
	t_tetra *roam;

	roam = head;
	while (roam)
	{
		i = 0;
		j = -1;
		while (roam->x[i] > 0)
		{
			i++;
			if (i > 3)
			{
				while (j < 4)
					roam->x[j++]--;
				i = 0;
				j = -1;
			}
		}
		roam = roam->next;
	}
	return (head);
}

t_tetra	*tetra_placement_y(t_tetra *head)
{
	int		i;
	int		j;
	t_tetra *roam;

	roam = head;
	while (roam)
	{
		i = 0;
		j = -1;
		while (roam->y[i] > 0)
		{
			i++;
			if (i > 3)
			{
				while (j < 4)
					roam->y[j++]--;
				i = 0;
				j = -1;
			}
		}
		roam = roam->next;
	}
	return (head);
}

t_tetra	*tetra_placement(t_tetra *head)
{
	if (!head)
		return (NULL);
	head = tetra_placement_x(head);
	head = tetra_placement_y(head);
	return (head);
}
