# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adbaich <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 01:46:30 by adbaich           #+#    #+#              #
#    Updated: 2022/02/03 02:05:45 by adbaich          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = so_long.c \
	   get_next_line.c \
	   get_next_line_utils.c \

OBJS = so_long.o \
	   get_next_line.o \
	   get_next_line_utils.o \


NAME = so_long

CC = cc -fsanitize=address -lmlx -framework OpenGL -framework AppKit\

RM = rm -f

FLAGS = -Wall -Wextra -Werror

all: ${NAME}

${OBJS}:
	${CC} ${FLAGS} ${SRCS}

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

flcean: clean
	${RM} ${NAME}

re: fclean all
