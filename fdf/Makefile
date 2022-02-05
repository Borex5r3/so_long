# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 01:46:30 by adbaich           #+#    #+#              #
#    Updated: 2022/02/05 18:19:04 by adbaich          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = so_long.c \
	   get_next_line.c \
	   get_next_line_utils.c \
	   move_right.c \
	   check_map.c \
	   draw_map.c \
	   key_code.c \
	   check_map_elements.c \
	   check_last.c \
	   fill_matrice.c \
	   check_ext.c \
	   ft_putnbr_fd.c \

NAME = so_long

CC = cc -g

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

MFLAGS = -lmlx -framework OpenGL -framework AppKit

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${MFLAGS} ${SRCS} -o ${NAME}

clean:
	${RM} ${NAME}

fclean: clean

re: fclean all
