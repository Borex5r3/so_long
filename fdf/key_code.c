/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_code.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 00:54:21 by adbaich           #+#    #+#             */
/*   Updated: 2022/02/04 22:46:48 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <stdio.h>
#include "so_long.h"

static void	move_left(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->h)
	{
		j = 0;
		while (vars->matrice[i][j])
		{
			if (vars->matrice[i][j] == 'P' &&
					vars->matrice[i][j - 1] != '1')
			{
				vars->matrice[i][j] = '0';
				vars->matrice[i][--j] = 'P';
				vars->count++;
				printf("%d\n", vars->count);
			}
			j++;
		}
		i++;
	}
}

static void	move_up(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->h)
	{
		j = 0;
		while (vars->matrice[i][j])
		{
			if (vars->matrice[i][j] == 'P' &&
					vars->matrice[i - 1][j] != '1')
			{
				vars->matrice[i][j] = '0';
				vars->matrice[--i][j] = 'P';
				vars->count++;
				printf("%d\n", vars->count);
			}
			j++;
		}
		i++;
	}
}

static void	move_down(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->h)
	{
		j = 0;
		while (vars->matrice[i][j])
		{
			if (vars->matrice[i][j] == 'P' &&
					vars->matrice[i + 1][j] != '1')
			{
				vars->matrice[i][j] = '0';
				vars->matrice[++i][j] = 'P';
				vars->count++;
				printf("%d\n", vars->count);
			}
			j++;
		}
		i++;
	}
}

static void	move_right_help(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->h)
	{
		j = 0;
		while (vars->matrice[i][j])
		{
			move_right(vars, &vars->matrice[i][j], \
			&vars->matrice[i][j + 1], &j);
			j++;
		}
		i++;
	}
}

int	key_code(int key, t_vars *vars)
{
	if (key == 53)
	{
		exit(0);
		system("leaks");
	}
	else if (key == 2)
		move_right_help(vars);
	else if (key == 0)
		move_left(vars);
	else if (key == 13)
		move_up(vars);
	else if (key == 1)
		move_down(vars);
	draw_map(vars);
	return (0);
}
