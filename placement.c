/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 16:57:49 by srobin            #+#    #+#             */
/*   Updated: 2019/05/03 19:23:54 by srobin           ###   ########.fr       */
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

	ay = 0;
	if (!head)
		return (NULL);
	roam = head;
	while (roam)
	{
		ax = 0;
		i = 0;
		while (i < 4 && ay < sq_size - 1)
		{	
			if (square[roam->y[i] + ay][roam->x[i] + ax] == '.')
				i++;
			else if (square[roam->y[i] + ay][roam->x[i] + ax] >= 'A' && 
				square[roam->y[i] + ay][roam->x[i] + ax] <= 'Z')
			{
				ax++;
				i = 0;
			}
/*			else
			{
				i = 0;
				ax++;
			}
*/			else if (square[roam->y[i] + ay][roam->x[i] + ax] == '\0')
			{
				ay++;
				ax = 0;
				i = 0;
			}
/*			if (square[ay][sq_size - 1] != '.')
			{
				ay++;
				ax = 0;
			}
*/		}
		j = 0;
		while (j < 4)
		{
			square[roam->y[j] + ay][roam->x[j] + ax] = roam->id;
			j++;
		}
		roam = roam->next;
	}
	return (square);
}
