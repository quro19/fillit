/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbackaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 17:41:27 by qbackaer          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/05/03 15:54:36 by srobin           ###   ########.fr       */
=======
/*   Updated: 2019/05/03 18:52:28 by srobin           ###   ########.fr       */
>>>>>>> srobin
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
	int		fd;
	t_tetra	*head;
	char	**square;

	head = NULL;
	if (argc != 2)
	{
		ft_putendl("usage: ./fillit <input>");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (!(head = record_tetra(fd, head)))
	{
		ft_putendl("error");
		return (1);
	}
	if (!is_valid_list(head))
	{
		ft_putendl("error: invalid tetraminos.");
		return (1);
	}
	head = tetra_placement(head);
	head = tetra_id(head);
	head = tetra_placement(head);
	square = init_square(15);
	square = tetra_into_square(head, square, 15);
	print_square(square);
	return (0);
}
