/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 00:36:34 by adbaich           #+#    #+#             */
/*   Updated: 2022/02/04 00:37:43 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <stdio.h>
#include "so_long.h"

static int	check_c(t_vars *vars)
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
			printf("%d\n", vars->count);
			exit(0);
		}
		else if (*p != 'E')
		{
			*c = '0';
			*p = 'P';
			vars->count++;
			*j = *j + 1;
			printf("%d\n", vars->count);
		}
	}
}
