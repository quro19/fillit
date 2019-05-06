/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 16:57:49 by srobin            #+#    #+#             */
/*   Updated: 2019/05/06 18:09:02 by qbackaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**tetra_into_square(t_tetra *head, char **square, int sq_size)
{
	t_tetra		*roam;
	int			j;
	t_offset	ofst;

	if (!head)
		return (NULL);
	roam = head;
	while (roam)
	{
		ofst.ay = 0;
		ofst.ax = 0;
		j = 0;
		if (!find_slot(square, roam, &ofst, sq_size))
			return (NULL);
		while (j < 4)
		{
			square[roam->y[j] + ofst.ay][roam->x[j] + ofst.ax] = roam->id;
			j++;
		}
		roam = roam->next;
	}
	return (square);
}

int		find_slot(char **sq, t_tetra *roam, t_offset *ofst, int sz)
{
	int		i;

	i = 0;
	while (i < 4 && ofst->ay < sz - 1)
	{
		if (sq[roam->y[i] + ofst->ay][roam->x[i] + ofst->ax] == '.')
			i += 1;
		else if (sq[roam->y[i] + ofst->ay][roam->x[i] + ofst->ax] >= 'A' &&
				sq[roam->y[i] + ofst->ay][roam->x[i] + ofst->ax] <= 'Z')
		{
			ofst->ax += 1;
			i = 0;
		}
		else if (sq[roam->y[i] + ofst->ay][roam->x[i] + ofst->ax] == '\0')
		{
			ofst->ay += 1;
			ofst->ax = 0;
			i = 0;
		}
	}
	if (i < 4)
		return (0);
	return (1);
}
