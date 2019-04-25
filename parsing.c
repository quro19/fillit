/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 18:59:45 by srobin            #+#    #+#             */
/*   Updated: 2019/04/25 17:28:46 by qbackaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetra		*record_tetra(int fd, t_tetra *head)
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
			return (NULL);
		}
		// cree une nouvelle node
		// remplit
	}
	return (head);
}
