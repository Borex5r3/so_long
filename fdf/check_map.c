/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 00:43:38 by adbaich           #+#    #+#             */
/*   Updated: 2022/02/06 18:58:33 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <stdio.h>
#include "so_long.h"

static void	check_wall(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->h)
	{
		j = 0;
		while (vars->matrice[i][j])
		{
			if (vars->matrice[0][j] != '1'
				|| vars->matrice[vars->h - 1][j] != '1'
					|| vars->matrice[i][0] != '1'
						|| vars->matrice[i][vars->w - 1] != '1')
			{
				write(1, "Error\nCheck The Wall !!", 23);
				exit(0);
			}
			j++;
		}
		i++;
	}
}

static void	check_all( t_vars *vars, int player, int collect, int door)
{
	check_map_elements(vars);
	if (player == 0 || door == 0
		|| collect == 0)
	{
		write(1, "Error\nThe game requires at least P, C and E !!", 46);
		exit(0);
	}
}

static void	check_pc(t_vars *vars, int *player, int *collect)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->h)
	{
		j = 0;
		while (vars->matrice[i][j])
		{
			if (vars->matrice[i][j] == 'P')
			{
				if (*player >= 1)
				{
					write(1, "Error\nThe game requires one player !!", 37);
					exit(0);
				}
				*player = *player + 1;
			}
			else if (vars->matrice[i][j] == 'C')
				*collect = *collect + 1;
			j++;
		}
		i++;
	}
}

static void	check_door(t_vars *vars, int *door)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->h)
	{
		j = 0;
		while (vars->matrice[i][j])
		{
			if (vars->matrice[i][j] == 'E')
				*door = *door + 1;
			j++;
		}
		i++;
	}
}

void	check_map(t_vars *vars)
{
	int	player;
	int	door;
	int	collect;

	player = 0;
	door = 0;
	collect = 0;
	check_wall(vars);
	check_pc(vars, &player, &collect);
	check_door(vars, &door);
	check_all(vars, player, collect, door);
}
