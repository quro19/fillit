/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 16:57:49 by srobin            #+#    #+#             */
/*   Updated: 2019/05/03 18:35:51 by srobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**tetra_into_square(t_tetra *head, char **square, int sq_size)
{
	t_tetra	*roam;
	int		i;
	int		j;
	int		ax;
	int		ay;

	sq_size++;	
	ax = 0;
	ay = 0;	
	if (!head)
		return (NULL);
	roam = head;
	while (roam)
	{
		i = 0;
		while (square[roam->y[i] + ay][roam->x[i] + ax] == '.')
		{	
			printf("I = %d\n", i);
			if (i == 3)
			{
				j = 0;
				while (j < 4)
				{
					printf("\tJ = %d\n", j);
					square[roam->y[j] + ay][roam->x[j] + ax] = roam->id;
					j++;
				}
				i = -1;
			}
			if (square[roam->y[i] + ay][roam->x[i] + ax] != '.')
			{
				ax++;
				continue ;
			}
			i++;
		}
		roam = roam->next;
	}
	return (square);
}
