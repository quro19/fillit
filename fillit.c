/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbackaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 17:41:27 by qbackaer          #+#    #+#             */
/*   Updated: 2019/05/07 18:27:09 by srobin           ###   ########.fr       */
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

t_tetra	*get_tetras(char *path, t_tetra *head)
{
	int fd;

	fd = open(path, O_RDONLY);
	if (!(head = record_tetra(fd, head)) || !is_valid_list(head))
		return (NULL);
	if (!(head = tetra_id(tetra_placement(head))))
		return (NULL);
	return (head);
}

void	solve(t_tetra *head)
{
	int i;
	char	**square;

	square = NULL;
	i = 0;
	while (1)
	{
		printf("LOOP %d\n", i);
		square = init_square(smallest_sq(head) + i);
		if (!(tetra_into_square(head, square, smallest_sq(head) + i)))
			i++;
		else
			break ;
	}
	print_square(square);
}

int		main(int argc, char **argv)
{
	t_tetra	*head;
	char	**square;

	square = NULL;
	head = NULL;
	if (argc != 2)
	{
		ft_putendl("usage: ./fillit <input>");
		return (1);
	}
	if (!(head = get_tetras(argv[1], head)))
	{
		ft_putendl("ERROR.");
		return (0);
	}
	solve(head);
	return (0);
}
