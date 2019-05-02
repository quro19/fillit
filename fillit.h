/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbackaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 17:46:07 by qbackaer          #+#    #+#             */
/*   Updated: 2019/05/02 20:20:57 by srobin           ###   ########.fr       */
/*   Updated: 2019/04/24 19:09:43 by srobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct		s_tetra
{
	int				x[4];
	int				y[4];
	struct s_tetra	*next;
}					t_tetra;

int					check_char(char c, int p);
int					check_format(char *str);
t_tetra				*record_tetra(int fd, t_tetra *head);
int					is_valid_list(t_tetra *head);
int					is_valid_tetra(t_tetra *node);
int					compare_coords(int ox, int oy, int cx, int cy);
t_tetra				*add_node(t_tetra *head, char *buff);
t_tetra				*coord(char *str, t_tetra *node);
void				read_list(t_tetra *head);
int					count_blocks(t_tetra *head);
int					smallest_square(int n_blocks);
t_tetra				*tetra_placement(t_tetra *head);
#endif
