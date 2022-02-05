/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_last.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:16:54 by adbaich           #+#    #+#             */
/*   Updated: 2022/02/05 22:14:48 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <stdio.h>
#include "so_long.h"

void	move_left(t_vars *vars, char *c, char *p, int *j)
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
			*j = *j - 1;
			ft_putnbr_fd(vars->count);
			write(1, "\n", 1);
		}
	}
}

void	move_up(t_vars *vars, char *c, char *p, int *i)
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
			*i = *i - 1;
			ft_putnbr_fd(vars->count);
			write(1, "\n", 1);
		}
	}
}

void	move_down(t_vars *vars, char *c, char *p, int *i)
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
			*i = *i + 1;
			ft_putnbr_fd(vars->count);
			write(1, "\n", 1);
		}
	}
}

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
				write(1, "Error\nCheck The Wall xd!!", 25);
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
