/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 00:22:34 by adbaich           #+#    #+#             */
/*   Updated: 2022/01/07 05:02:09 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <stdio.h>
#include "so_long.h"

int	key_code(int key)
{
	if (key == 53)
		exit(0);
	printf("%d\n", key);
	return (0);
}

int	exiit(void)
{
	exit(0);
	return (0);
}

void	so_long(int	b, char **matrice)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	void	*img_ptr1;
	void	*img_ptr2;
	void	*img_ptr3;

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
	//char 	matrice[5][50] = {"110110110111", "010010010001", "010110110001","010010010001","010110110001"};
	int		w = 0;
	int		h = 0;

	i = 0;
	xw = 50;
	yw = 50;
	mlx_ptr = mlx_init();
	i = 0;
	while (matrice[0][i])
	{
		i++;
		w++;
	}

	i = 0;
	while (i < b)
	{
		i++;
		h++;
	}
	//h = 4;
	//w = w * 50;
	//h = h * 50;
	win_ptr = mlx_new_window(mlx_ptr, w * xw, h * yw, "first try");
	img_ptr = mlx_xpm_file_to_image(mlx_ptr, "lawn.xpm", &x, &y);
	img_ptr3 = mlx_xpm_file_to_image(mlx_ptr, "door.xpm", &x, &y);
	mlx_key_hook(win_ptr, key_code, 0);
	mlx_hook(win_ptr, 17, 1L<<17, exiit, 0);
	img_ptr1 = mlx_xpm_file_to_image(mlx_ptr, "eagle.xpm", &x, &y);
	img_ptr2 = mlx_xpm_file_to_image(mlx_ptr, "mouse.xpm", &x, &y);

	i = 0;
	y1 = 0;
	while (i < h)
	{
		x1 = 0;
		j = 0;
		while (x1 < w * xw)
		{
			if (matrice[i][j] == '1')
				mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, x1, y1);
			else if (matrice[i][j] == 'P')
				mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr1, x1, y1);
			else if (matrice[i][j] == 'C')
				mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr2, x1, y1);
			else if (matrice[i][j] == 'E')
				mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr3, x1, y1);



			x1 = x1 + xw;
			j++;
		}
		y1 = y1 + yw;
		i++;
	}	
	//DDA algo
	/*i = 0;
	y1 = 50;
	while (matrice[i] && y1 <= 650)
	{
		j = 0;
		x1 = 50;
		while (x1 < 650)
		{
			k = 0;
			dx = (x1 + 50) - x1;
			dy = y1 - y1;
			printf("%f ==> x1 , %f ==> y1\n", x1, y1);
			if (abs((int)dx) > abs((int)dy))
				step = abs((int)dx);
			else
				step = abs((int)dy);
			xinc = dx / step;
			yinc = dy / step;
			while (k++ < step)
			{
				mlx_pixel_put(mlx_ptr, win_ptr, x1, y1, 0x0000FF00);
				//mlx_pixel_put(mlx_ptr, win_ptr, y1, x1, 0x0000FF00);
				x1 = x1 + xinc;
				y1 = y1 + yinc;
			}
		
		}
		i++;
		y1 = y1 + 50;
	}
	k = 0;
		dx = x1 - x1;
		dy = 50 - y1;
		if (abs((int)dx) > abs((int)dy))
			step = abs((int)dx);
		else
			step = abs((int)dy);
		xinc = dx / step;
		yinc = dy / step;
		while (k++ < step)
			{
				mlx_pixel_put(mlx_ptr, win_ptr, x1, y1, 0x0000FF00);
				mlx_pixel_put(mlx_ptr, win_ptr, y1, x1, 0x0000FF00);
				x1 = x1 + xinc;
				y1 = y1 + yinc;
			}*/



	//printf("x1 == %f ******* y1 == %f\n", x1, y1);

	/*y1 = 50;
	while (y1 <= 650)
	{
		x1 = 50;
		while (x1 <= 650)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x1, y1, 0x0000FF00);
			x1++;
		}
		y1 = y1 + 50;
	}
	x1 = 50;
	while (x1 <= 650)
	{
		y1 = 50;
		while (y1 <= 650)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x1, y1, 0x0000FF00);
			y1++;
		}
		x1 = x1 + 50;
	}*/

	mlx_loop(mlx_ptr);
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
	char	**mtr;

	i = 0;
	r = 0;
	if (ac == 2)
	{
		fd = open(av[ac - 1], O_RDWR);
		while (get_next_line(fd))
			r++;

		//r == b in so_long
		mtr = malloc(sizeof(char*) * r + 1);
		close(fd);
		fd = open(av[ac - 1], O_RDWR);
		printf("%d\n", fd);
		while (i < r)
		{
			mtr[i] = rm_bn(get_next_line(fd));
			printf("%s\n", mtr[i]);
			i++;
		}
		printf("a\n");
		so_long(r, mtr);

		

	}
	return (0);
}
