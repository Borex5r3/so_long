/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:04:57 by adbaich           #+#    #+#             */
/*   Updated: 2022/01/06 20:17:01 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 42
#include <fcntl.h>

char	*get_next_line(int fd);
void	ft_free(char **s);
size_t	ft_strlen(char	*s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_reading(int fd, char *d_main);
char	*ft_returning(char	*d_main);
char	*ft_modifying(char *d_main);
void	ft_strlcpy(char *dst, const char	*src);

#endif
