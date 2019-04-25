/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbackaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 17:46:07 by qbackaer          #+#    #+#             */
/*   Updated: 2019/04/25 18:23:47 by qbackaer         ###   ########.fr       */
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
t_tetra				*add_node(t_tetra *head, char *buff);
t_tetra				*coord(char *str, t_tetra *node);
void				read_list(t_tetra *head);

#endif
