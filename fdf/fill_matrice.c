/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_matrice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:28:35 by adbaich           #+#    #+#             */
/*   Updated: 2022/02/06 19:10:09 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <stdio.h>
#include "so_long.h"

void	check_fd(int fd)
{
	if (fd < 0)
	{
		write(1, "fd is negative !", 16);
		exit(0);
	}
}

int	calculate_r(t_vars vars, int fd)
{
	int	r;

	r = 0;
	while (vars.str)
	{
		r++;
		free(vars.str);
		vars.str = get_next_line(fd);
		if (vars.str[0] != '1')
		{
			free(vars.str);
			write(1, "Error\nCheck The Wall !!\n", 24);
			exit(0);
		}
	}
	return (r);
}

void	fill_matrice(char *p, t_vars vars, int r)
{
	int	fd;
	int	i;

	fd = open(p, O_RDWR);
	check_fd(fd);
	i = 0;
	while (i < r)
	{
		vars.matrice[i] = rm_bn(get_next_line(fd));
		i++;
	}
	close(fd);
}
