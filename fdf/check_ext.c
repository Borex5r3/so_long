/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:16:45 by adbaich           #+#    #+#             */
/*   Updated: 2022/02/04 22:26:47 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <stdio.h>
#include "so_long.h"

int	ft_strncmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] -(unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	check_ext(char *p)
{
	char	m[5];
	int		i;

	i = 0;
	m[0] = '.';
	m[1] = 'b';
	m[2] = 'e';
	m[3] = 'r';
	m[4] = 0;
	i = ft_strlen(p) - 1;
	printf("%d\n", i);
	while (i >= 1)
	{
		if (p[i] == '.')
			break ;
		i--;
	}
	if (ft_strncmp(m, p + i))
	{
		printf("Error\nOnly .ber Extension !!");
		exit(0);
	}
}
