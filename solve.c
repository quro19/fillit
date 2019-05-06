/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbackaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:03:52 by qbackaer          #+#    #+#             */
/*   Updated: 2019/05/06 16:53:18 by qbackaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		smallest_square(int n_blocks)
{
	int	side_sz;

	side_sz = 0;
	while ((side_sz * side_sz) < n_blocks)
		side_sz++;
	return (side_sz);
}

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
