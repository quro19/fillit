/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbackaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 17:41:27 by qbackaer          #+#    #+#             */
/*   Updated: 2019/05/06 18:19:35 by qbackaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_char(char c, int p)
{
	if ((p + 1) % 5 == 0 || p == 20)
	{
		if (c != '\n')
		{
			ft_putendl("error: wrong format.");
			return (0);
		}
	}
	else if (c != '.' && c != '#')
	{
		ft_putendl("error: wrong format.");
		return (0);
	}
	return (1);
}

int		check_format(char *str)
{
	int i;
	int block_count;

	if (ft_strlen(str) != 21)
		return (0);
	i = 0;
	block_count = 0;
	while (str[i])
	{
		if (!check_char(str[i], i))
			return (0);
		if (str[i] == '#')
			block_count++;
		i++;
	}
	if (block_count != 4)
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	int		i;
	int		fd;
	t_tetra	*head;
	char	**square;

	square = NULL;
	head = NULL;
	if (argc != 2)
	{
		ft_putendl("usage: ./fillit <input>");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (!(head = record_tetra(fd, head)) || !is_valid_list(head))
	{
		ft_putendl("error");
		return (1);
	}
	head = tetra_id(tetra_placement(head));
	i = 0;
	while (!square)
	{
		square = init_square(smallest_sq(head) + i);
		if (!(square = tetra_into_square(head, square, smallest_sq(head) + i)))
			i++;
		else
			print_square(square);
	}
	return (0);
}
