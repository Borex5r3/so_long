/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:11:29 by adbaich           #+#    #+#             */
/*   Updated: 2022/02/05 18:17:20 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <stdio.h>
#include "so_long.h"

static int	check(int n)
{
	int	s;
	int	k;

	s = 1;
	k = n;
	if (n < 0)
	{
		k = n * -1;
		s++;
	}
	while ((k / 10) != 0)
	{
		k = k / 10;
		s++;
	}
	return (s);
}

static int	min_int(int *n)
{
	write(1, "-", 1);
	ft_putnbr_fd(2);
	*n = 147483648;
	return (2);
}

void	ft_putnbr_fd(int n)
{
	char	c;
	int		a;

	a = 0;
	if (n == -2147483648)
		a = min_int(&n);
	a = a + check(n);
	if (n < 0)
	{
		write(1, "-", 1);
		n = n * -1;
	}
	if (n > 9)
	{
		ft_putnbr_fd((n / 10));
		ft_putnbr_fd((n % 10));
	}
	else
	{
		c = n + 48;
		write(1, &c, 1);
	}
}
