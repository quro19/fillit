/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 18:59:45 by srobin            #+#    #+#             */
/*   Updated: 2019/05/06 17:27:02 by qbackaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetra	*record_tetra(int fd, t_tetra *head)
{
	int		i;
	int		ret;
	char	buff[22];

	i = 0;
	while ((ret = read(fd, buff, 21)))
	{
		if (i >= 26)
		{
			ft_putendl("error: too many tetraminos.");
			return (NULL);
		}
		buff[ret] = '\0';
		if (!check_format(buff) || !(head = add_node(head, buff)))
			return (NULL);
		i++;
		memset(buff, 0, ret);
	}
	if (!i && !ret)
	{
		ft_putendl("error: empty file.");
		return (NULL);
	}
	return (head);
}

int		is_valid_list(t_tetra *head)
{
	t_tetra	*roam;

	if (!head)
	{
		ft_putendl("error: empty list");
		return (0);
	}
	roam = head;
	while (roam)
	{
		if (!is_valid_tetra(roam))
			return (0);
		roam = roam->next;
	}
	return (1);
}

int		is_valid_tetra(t_tetra *node)
{
	int i;
	int j;
	int valid_block;
	int valid_tetra;

	i = 0;
	valid_tetra = 0;
	valid_block = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (compare_coords(node->x[i], node->y[i], node->x[j], node->y[j]))
				valid_block += 1;
			j++;
		}
		if (!valid_block)
			return (0);
		valid_tetra++;
		i++;
	}
	if (valid_tetra != 4 || valid_block < 6)
		return (0);
	return (1);
}

int		compare_coords(int ox, int oy, int cx, int cy)
{
	if (ox == cx && (oy == cy + 1 || oy == cy - 1))
		return (1);
	if (oy == cy && (ox == cx + 1 || ox == cx - 1))
		return (1);
	return (0);
}
