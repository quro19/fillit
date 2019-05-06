/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbackaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:03:52 by qbackaer          #+#    #+#             */
/*   Updated: 2019/05/06 19:56:07 by qbackaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**init_square(int side_sz)
{
	char	**empty_sq;
	int		i;
	int		j;

	if (!(empty_sq = malloc(sizeof(empty_sq) * side_sz + 1)))
		return (NULL);
	i = 0;
	while (i < side_sz)
	{
		if (!(empty_sq[i] = malloc(side_sz + 1)))
			return (NULL);
		j = 0;
		while (j < side_sz)
		{
			empty_sq[i][j] = '.';
			j++;
		}
		empty_sq[i][j] = '\0';
		i++;
	}
	empty_sq[side_sz] = NULL;
	return (empty_sq);
}

void	print_square(char **sq)
{
	char **roam;

	roam = sq;
	while (*roam)
	{
		printf("%s\n", *roam);
		roam++;
	}
}
/*
void	print_tetra(t_tetra *node)
{
	int x;
	int y;

	y = 0;
	while (i < 3)
	{
		x = 0;
		while (x < 3)
		{
			if 

			x++;
		}
		y++;
	}
}*/
