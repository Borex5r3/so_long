/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 00:49:23 by adbaich           #+#    #+#             */
/*   Updated: 2022/02/04 00:51:31 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <stdio.h>
#include "so_long.h"

static void	put_pcew(t_vars *vars, char c, int x1, int y1)
{
	if (c == '1')
		mlx_put_image_to_window(vars->mlx_ptr, \
		vars->win_ptr, vars->img_ptr, x1, y1);
	else if (c == 'P')
		mlx_put_image_to_window(vars->mlx_ptr, \
		vars->win_ptr, vars->img_ptr1, x1, y1);
	else if (c == 'C')
		mlx_put_image_to_window(vars->mlx_ptr, \
		vars->win_ptr, vars->img_ptr2, x1, y1);
	else if (c == 'E')
		mlx_put_image_to_window(vars->mlx_ptr, \
		vars->win_ptr, vars->img_ptr3, x1, y1);
}

void	draw_map(t_vars *vars)
{
	int	i;
	int	j;
	int	y1;
	int	x1;

	i = 0;
	y1 = 0;
	mlx_clear_window(vars->mlx_ptr, vars->win_ptr);
	while (i < vars->h)
	{
		x1 = 0;
		j = 0;
		while (x1 < vars->w * vars->xw)
		{
			put_pcew(vars, vars->matrice[i][j], x1, y1);
			x1 = x1 + vars->xw;
			j++;
		}
		y1 = y1 + vars->yw;
		i++;
	}
}
