# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 01:46:30 by adbaich           #+#    #+#              #
#    Updated: 2022/02/03 18:59:51 by adbaich          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = so_long.c \
	   get_next_line.c \
	   get_next_line_utils.c \

OBJS = ${SRCS: .c=.o}


NAME = so_long

CC = cc

RM = rm -f

FLAGS = -Wall -Wextra -Werror

MFLAGS = -fsanitize=address -lmlx -framework OpenGL -framework AppKit

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${FLAGS} ${MFLAGS} ${OBJS} -o ${NAME}

clean:
	${RM} ${OBJS}

flcean: clean
	${RM} ${NAME}

re: fclean all
