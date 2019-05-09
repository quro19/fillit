/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 16:57:49 by srobin            #+#    #+#             */
/*   Updated: 2019/05/09 18:44:30 by qbackaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	clear_old_coord(t_tetra *tetra, char **square, t_offset *ofst)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		square[tetra->y[i] + ofst->ay][tetra->x[i] + ofst->ax] = '.';
		i++;
	}
}

void	place_tetra(char **square, t_tetra *node, t_offset ofst)
{
	int j;

	j = 0;
	while (j < 4)
	{
		square[node->y[j] + ofst.ay][node->x[j] + ofst.ax] = node->id;
		j++;
	}
}

int		tetra_into_square(t_tetra *head, char **square, int sq_size)
{
	t_tetra		*roam;
	int			j;
	t_offset	ofst;

	if (!head)
		return (-1);
	roam = head;
	ofst.ay = 0;
	ofst.ax = 0;
	while (1)
	{
		j = 0;
		if (!find_slot(square, roam, &ofst, sq_size))
			return (0);
		place_tetra(square, roam, ofst);
		if (!tetra_into_square(roam->next, square, sq_size))
		{
			clear_old_coord(head, square, &ofst);
			ofst.ax++;
		}
		else
			break ;
	}
	return (1);
}

int		find_slot(char **sq, t_tetra *roam, t_offset *ofst, int sz)
{
	int		i;

	i = 0;
	while (i < 4 && (ofst->ay + roam->y[i]) < sz)
	{
		if (sq[roam->y[i] + ofst->ay][roam->x[i] + ofst->ax] == '.')
			i++;
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
