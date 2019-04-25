/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 18:59:45 by srobin            #+#    #+#             */
/*   Updated: 2019/04/24 19:48:52 by qbackaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		record_tetra(int fd)
{
	int		ret;
	char	buf[22];

	while ((ret = read(fd, buf, 21)))
	{
		printf("RET = %d\n", ret);
		buf[ret] = '\0';
		if (!check_format(buf))
		{
			ft_putendl("error, u fucked up");
			return (0);
		}
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int fd;

	if (argc != 2)
	{
		ft_putendl("usage: ./fillit <input>");
		return (1);
	}	

	fd = open(argv[1], O_RDONLY);
	record_tetra(fd);

	return (0);
}
