/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbackaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 17:46:07 by qbackaer          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/04/24 19:45:22 by qbackaer         ###   ########.fr       */
=======
/*   Updated: 2019/04/24 19:09:43 by srobin           ###   ########.fr       */
>>>>>>> c03044ff9164b6e47c97b410bfd11b4ba3bffddd
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

<<<<<<< HEAD
int		check_char(char c, int p);
int		check_format(char *str);
int		record_tetra(int fd);
=======
# define BUFF_SIZE 21

typedef struct		s_tetra
{
	int		x[4];
	int		y[4];
}					t_tetra;
>>>>>>> c03044ff9164b6e47c97b410bfd11b4ba3bffddd

#endif
