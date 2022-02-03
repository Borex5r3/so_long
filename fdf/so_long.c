/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 00:22:34 by adbaich           #+#    #+#             */
/*   Updated: 2022/02/03 19:49:35 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <stdio.h>
#include "so_long.h"

int	check_c(t_vars *vars)
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

void	check_map(t_vars *vars)
{
	int	i;
	int	j;
	int	player;
	int	door;
	int	collect;

	i = 0;
	player = 0;
	door = 0;
	collect = 0;
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
				printf("Error\nCheck The Wall !!");
				exit(0);
			}
			if (vars->matrice[i][j] == 'P')
			{
				if (player >= 1)
				{
					printf("Error\nThe game requires at most one player !!");
					exit(0);
				}
				player++;
			}
			else if (vars->matrice[i][j] == 'C')
				collect++;
			else if (vars->matrice[i][j] == 'E')
			{
				if (door >= 1)
				{
					printf("Error\nThe game requires at most one exit !!");
					exit(0);
				}
				door++;
			}
			j++;
		}
		i++;
	}
	if (player == 0 || door == 0
		|| collect == 0)
	{
		printf("Error\nThe game requires at least P, C and E !!");
		exit(0);
	}
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
			if (vars->matrice[i][j] == '1')
				mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img_ptr, x1, y1);
			else if (vars->matrice[i][j] == 'P')
				mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img_ptr1, x1, y1);
			else if (vars->matrice[i][j] == 'C')
				mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img_ptr2, x1, y1);
			else if (vars->matrice[i][j] == 'E')
				mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img_ptr3, x1, y1);
			x1 = x1 + vars->xw;
			j++;
		}
		y1 = y1 + vars->yw;
		i++;
	}
}

int	key_code(int key, t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	if (key == 53)
		exit(0);
	else if (key == 2)
	{
		while (i < vars->h)
		{
			j = 0;
			while (vars->matrice[i][j])
			{
				if (vars->matrice[i][j] == 'P' &&
							vars->matrice[i][j + 1] != '1')
				{
					if (vars->matrice[i][j + 1] == 'E' && 
							check_c(vars))
						{
							vars->count++;
							printf("%d\n", vars->count);
							exit(0);
						}
					else if (vars->matrice[i][j + 1] != 'E')
					{
						vars->matrice[i][j] = '0';
						vars->matrice[i][++j] = 'P';
						vars->count++;
						printf("%d\n", vars->count);
					}
				}
				j++;
			}
			i++;
		}
		//draw_map(vars);
	}
	else if (key == 0)
	{
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
		//draw_map(vars);
	}
	else if (key == 13)
	{
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
		//draw_map(vars);	
	}
	else if (key == 1)
	{
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
		//draw_map(vars);	
	}
	draw_map(vars);
	return (0);
}

int	exiit(int key)
{
	if (key == 53)
		exit(0);
	else
		exit(0);
	return (0);
}

void	so_long(int	b, t_vars vars)
{
	int		i;
	int		x = 50;
	int		y = 50;

	vars.w = 0;
	vars.xw = 50;
	vars.yw = 50;
	vars.mlx_ptr = mlx_init();
	i = 0;
	while (vars.matrice[0][i])
	{
		i++;
		vars.w++;
	}
	vars.count = 0;
	i = 0;
	while (i < b)
	{
		i++;
		vars.h++;
	}
	check_map(&vars);
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, vars.w * vars.xw, vars.h * vars.yw, "first try");
	vars.img_ptr = mlx_xpm_file_to_image(vars.mlx_ptr, "lawn.xpm", &x, &y);
	vars.img_ptr3 = mlx_xpm_file_to_image(vars.mlx_ptr, "door.xpm", &x, &y);
	mlx_key_hook(vars.win_ptr, key_code, &vars);
	mlx_hook(vars.win_ptr, 17, 1L<<17, exiit, 0);
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
	int	fd;
	int	r;
	int	i;
	t_vars	vars;

	i = 0;
	r = 0;
	if (ac == 2)
	{
		fd = open(av[ac - 1], O_RDWR);
		while (get_next_line(fd))
			r++;
		vars.matrice = malloc(sizeof(char*) * r + 1);
		close(fd);
		fd = open(av[ac - 1], O_RDWR);
		while (i < r)
		{
			vars.matrice[i] = rm_bn(get_next_line(fd));
			i++;
		}
		so_long(r, vars);
	}
	else
	{
		printf("Please Enter One Map !\n");
	}
	return (0);
}

