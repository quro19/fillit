/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbackaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:03:52 by qbackaer          #+#    #+#             */
/*   Updated: 2019/05/09 18:48:05 by qbackaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**init_square(int side_sz)
{
	char	**empty_sq;
	int		i;
	int		j;

	if (!(empty_sq = malloc(sizeof(empty_sq) * (side_sz + 1))))
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
	empty_sq[i] = NULL;
	return (empty_sq);
}

void	print_square(char **sq)
{
	char **roam;

	roam = sq;
	while (*roam)
	{
		ft_putendl(*roam);
		roam++;
	}
}

void	free_square(char **sq)
{
	char **tmp;

	if (!sq)
		return ;
	tmp = sq;
	while (*tmp && **tmp)
	{
		ft_memset(*tmp, 0, ft_strlen(*tmp));
		free(*tmp);
		tmp++;
	}
	free(sq);
}
