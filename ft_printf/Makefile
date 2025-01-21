# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 19:07:18 by dangtran          #+#    #+#              #
#    Updated: 2025/01/18 15:26:43 by dangtran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc

CFLAGS= -Wall -Wextra -Werror -I${HEADER_DIR}

SRCS_DIR = 	./srcs/ft_putchar_fd.c		\
			./srcs/ft_putstr_fd.c		\
			./srcs/ft_putnbr_fd.c		\
			./srcs/ft_put_unsigned.c		\
			./srcs/ft_put_hex_upper.c	\
			./srcs/ft_put_hex_lower.c	\
			./srcs/ft_ptr_hex.c	\
			./srcs/ft_itoa.c	\
			./srcs/ft_printf.c	\
			./srcs/ft_uitoa.c	\
			./srcs/ft_strcmp.c	\

SRCS_OBJ = ${SRCS_DIR:.c=.o}

HEADER_DIR=./includes/

NAME= libftprintf.a

all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@ 

${NAME} : ${SRCS_OBJ}
	ar rc ${NAME} ${SRCS_OBJ}

clean :
	rm -f ${SRCS_OBJ}

fclean : clean
	rm -f ${NAME}

re : fclean all