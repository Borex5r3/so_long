/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_last.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:16:54 by adbaich           #+#    #+#             */
/*   Updated: 2022/02/04 16:43:58 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <stdio.h>
#include "so_long.h"

void	check_last(char *p, int r)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(p, O_RDWR);
	while (i < r)
	{	
		if (i == r - 2)
		{
			if (get_next_line(fd)[ft_strlen(get_next_line(fd)) - 1] != '1')
			{
				printf("Error\nCheck The Wall xd!!");
				exit(0);
			}
		}
		else
			get_next_line(fd);
		i++;
	}
	close(fd);
}
