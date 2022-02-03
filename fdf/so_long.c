/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 00:22:34 by adbaich           #+#    #+#             */
/*   Updated: 2022/02/03 02:08:19 by adbaich          ###   ########.fr       */
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

void	draw_map(t_vars *vars)
{
	int	i;
	int	j;
	int	y1;
	int	x1;
	int	xw;
	int	yw;

	xw = 50;
	yw = 50;
	i = 0;
	y1 = 0;
	mlx_clear_window(vars->mlx_ptr, vars->win_ptr);
	while (i < vars->h)
	{
		x1 = 0;
		j = 0;
		while (x1 < vars->w * xw)
		{
			if (vars->matrice[i][j] == '1')
				mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img_ptr, x1, y1);
			else if (vars->matrice[i][j] == 'P')
				mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img_ptr1, x1, y1);
			else if (vars->matrice[i][j] == 'C')
				mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img_ptr2, x1, y1);
			else if (vars->matrice[i][j] == 'E')
				mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img_ptr3, x1, y1);
			x1 = x1 + xw;
			j++;
		}
		y1 = y1 + yw;
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
	int		j;
	int		k;
	int		x = 50;
	int		y = 50;
	int		x1;
	int		y1;
	float	x2 = 50;
	float 	y2 = 0;
	float	dx;
	float	dy;
	float	step;
	float	xinc;
	float	yinc;
	float	xtmp = 0;
	float	ytmp = 0;
	int		xw;
	int		yw;
	int		key;
	//char 	matrice[5][50] = {"110110110111", "010010010001", "010110110001","010010010001","010110110001"};
	vars.h = 0;
	vars.w = 0;
	xw = 50;
	yw = 50;
	//vars = malloc(sizeof(t_vars));
	vars.mlx_ptr = mlx_init();
	//printf("a\n");
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
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, vars.w * xw, vars.h * yw, "first try");
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

		//r == b in so_long
		vars.matrice = malloc(sizeof(char*) * r + 1);
		close(fd);
		fd = open(av[ac - 1], O_RDWR);
		//printf("%d\n", fd);
		while (i < r)
		{
			vars.matrice[i] = rm_bn(get_next_line(fd));
			i++;
		}
		//printf("a\n");
		so_long(r, vars);

		

	}
	return (0);
}

