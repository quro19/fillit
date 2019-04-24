/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 18:59:45 by srobin            #+#    #+#             */
/*   Updated: 2019/04/24 19:23:13 by srobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

struct	s_tetra		record_tetra(int fd)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
	}
}
