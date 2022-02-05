/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_last.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:16:54 by adbaich           #+#    #+#             */
/*   Updated: 2022/02/05 15:20:33 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <stdio.h>
#include "so_long.h"

void	check_last(char *p, int r)
{
	int		i;
	int		fd;
	char	*l;

	i = -1;
	fd = open(p, O_RDWR);
	while (++i < r)
	{
		if (i == r - 1)
		{
			l = get_next_line(fd);
			if (l[ft_strlen(l) - 1] != '1')
			{
				printf("Error\nCheck The Wall xd!!");
				exit(0);
			}
			free(l);
		}
		else
		{
			l = get_next_line(fd);
			free(l);
		}
	}
	close(fd);
}
