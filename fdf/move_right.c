/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 00:36:34 by adbaich           #+#    #+#             */
/*   Updated: 2022/02/05 21:14:02 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <stdio.h>
#include "so_long.h"

int	check_c(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->h)
	{
		j = 0;
		while (vars->matrice[i][j])
		{
			if (vars->matrice[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	move_right(t_vars *vars, char *c, char *p, int *j)
{
	if (*c == 'P' && *p != '1')
	{
		if (*p == 'E' && check_c(vars))
		{
			vars->count++;
			ft_putnbr_fd(vars->count);
			write(1, "\n", 1);
			exit(0);
		}
		else if (*p != 'E')
		{
			*c = '0';
			*p = 'P';
			vars->count++;
			*j = *j + 1;
			ft_putnbr_fd(vars->count);
			write(1, "\n", 1);
		}
	}
}
