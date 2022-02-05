/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:04:57 by adbaich           #+#    #+#             */
/*   Updated: 2022/02/05 15:30:53 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 42
# include <fcntl.h>

typedef struct s_vars
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	void	*img_ptr1;
	void	*img_ptr2;
	void	*img_ptr3;
	void	*img_ptr4;
	char	**matrice;
	int		h;
	int		w;
	int		xw;
	int		yw;
	int		count;
	char	*str;

}	t_vars;

char	*get_next_line(int fd);
void	ft_free(char **s);
int		ft_strlen(char	*s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_reading(int fd, char *d_main);
char	*ft_returning(char	*d_main);
char	*ft_modifying(char *d_main);
void	move_right(t_vars *vars, char *c, char *p, int *j);
void	check_map(t_vars *vars);
void	draw_map(t_vars *vars);
int		key_code(int key, t_vars *vars);
void	check_map_elements(t_vars *vars);
void	check_last(char *p, int r);
void	fill_matrice(char *p, t_vars vars, int r);
char	*rm_bn(char *p);
void	check_ext(char *p);
int		calculate_r(t_vars vars, int fd);

#endif
