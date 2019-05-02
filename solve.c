/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbackaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:03:52 by qbackaer          #+#    #+#             */
/*   Updated: 2019/05/02 19:12:52 by qbackaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		smallest_square(int	n_blocks)
{
	int		side_sz;

	side_sz = 0;
	while ((side_sz * side_sz) < n_blocks)
		side_sz++;
	return (side_sz);
}
