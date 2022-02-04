/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_matrice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:28:35 by adbaich           #+#    #+#             */
/*   Updated: 2022/02/04 16:44:46 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <stdio.h>
#include "so_long.h"

void	fill_matrice(char *p, t_vars vars, int r)
{
	int	fd;
	int	i;

	fd = open(p, O_RDWR);
	i = 0;
	while (i < r)
	{
		vars.matrice[i] = rm_bn(get_next_line(fd));
		i++;
	}
}
