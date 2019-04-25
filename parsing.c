/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 18:59:45 by srobin            #+#    #+#             */
/*   Updated: 2019/04/25 18:19:04 by qbackaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetra		*record_tetra(int fd, t_tetra *head)
{
	int		ret;
	char	buff[22];

	while ((ret = read(fd, buff, 21)))
	{
		printf("LOOP\n");
		buff[ret] = '\0';
		if (!check_format(buff))
		{
			ft_putendl("error, u fucked up");
			return (NULL);
		}
		if (!(head = add_node(head, buff)))
			return (NULL);
	}
	return (head);
}
