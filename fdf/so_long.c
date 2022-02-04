/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 00:22:34 by adbaich           #+#    #+#             */
/*   Updated: 2022/02/04 18:39:19 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <stdio.h>
#include "so_long.h"

int	exiit(int key)
{
	if (key == 53)
		exit(0);
	else
		exit(0);
	return (0);
}

void	so_long_help(t_vars *vars, int b)
{
	int		i;

	vars->w = 0;
	vars->xw = 50;
	vars->yw = 50;
	vars->mlx_ptr = mlx_init();
	i = 0;
	while (vars->matrice[0][i])
	{
		i++;
		vars->w++;
	}
	vars->count = 0;
	i = 0;
	while (i < b)
	{
		i++;
		vars->h++;
	}
}

void	so_long(int b, t_vars vars)
{
	int	x;
	int	y;

	x = 50;
	y = 50;
	so_long_help(&vars, b);
	check_map(&vars);
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, vars.w * vars.xw, \
	vars.h * vars.yw, "first try");
	vars.img_ptr = mlx_xpm_file_to_image(vars.mlx_ptr, "lawn.xpm", &x, &y);
	vars.img_ptr3 = mlx_xpm_file_to_image(vars.mlx_ptr, "door.xpm", &x, &y);
	mlx_key_hook(vars.win_ptr, key_code, &vars);
	mlx_hook(vars.win_ptr, 17, 1L << 17, exiit, 0);
	vars.img_ptr1 = mlx_xpm_file_to_image(vars.mlx_ptr, "eagle.xpm", &x, &y);
	vars.img_ptr2 = mlx_xpm_file_to_image(vars.mlx_ptr, "mouse.xpm", &x, &y);
	draw_map(&vars);
	mlx_loop(vars.mlx_ptr);
}

char	*rm_bn(char *p)
{
	int	i;

	i = 0;
	while (p[i])
		i++;
	i--;
	if (p[i] == '\n')
		p[i] = '\0';
	return (p);
}

int	main(int ac, char **av)
{
	int		fd;
	int		r;
	int		i;
	t_vars	vars;

	i = 0;
	r = 0;
	if (ac == 2)
	{
		fd = open(av[ac - 1], O_RDWR);
		while (get_next_line(fd))
			r++;
		vars.matrice = malloc(sizeof(char *) * r + 1);
		close(fd);
		check_last(av[ac - 1], r);
		fill_matrice(av[ac - 1], vars, r);
		so_long(r, vars);
	}
	else
		printf("Please Enter One Map !\n");
	return (0);
}
