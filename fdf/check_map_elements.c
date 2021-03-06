/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 01:14:38 by adbaich           #+#    #+#             */
/*   Updated: 2022/02/06 19:16:53 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <stdio.h>
#include "so_long.h"

void	check_vars(t_vars vars)
{
	if (!vars.str)
	{	
		write(1, "Map is empty !!\n", 16);
		exit(0);
	}
	else if (!vars.matrice)
		exit(0);
}

void	check_map_elements(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->h)
	{
		j = 0;
		while (vars->matrice[i][j])
		{
			if (vars->matrice[i][j] != '0'
				&& vars->matrice[i][j] != 'C'
					&& vars->matrice[i][j] != 'P'
						&& vars->matrice[i][j] != 'E'
							&& vars->matrice[i][j] != '1')
			{
				write(1, "Error!\nOnly P, E, 0, 1 and C !!", 31);
				exit(0);
			}
			j++;
		}
		i++;
	}
}
