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

void	print_line(char *str)
{
	int	i;
	char	buff[2];

	buff[0] = '.';
	buff[1] = '\0';
	i = 0;
	while (str[i])
	{
		buff[0] = str[i];
		if (str[i] == '.')
			printf(WHT);
		else if (str[i] % 6 == 0)
			printf(RED);
		else if (str[i] % 6 == 1)
			printf(GRN);
		else if (str[i] % 6 == 2)
			printf(YEL);
		else if (str[i] % 6 == 3)
			printf(MAG);
		else if (str[i] % 6 == 4)
			printf(CYN);
		else if (str[i] % 6 == 5)
			printf(CYN);
		printf("%s", buff);
		printf(RST);
		i++;
	}
	printf("\n");
}

void	print_square(char **sq)
{
	char **roam;

	roam = sq;
	while (*roam)
	{
		print_line(*roam);
		roam++;
	}
}
