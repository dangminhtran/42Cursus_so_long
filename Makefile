# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/20 19:29:02 by dangtran          #+#    #+#              #
#    Updated: 2025/01/17 19:27:02 by dangtran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= so_long

CC=cc

CFLAGS= -Wall -Wextra -Werror -I${HEADER_DIR} -g

SRCS_DIR = 	$(addprefix sources/, errors.c path.c graphics.c moves.c map.c so_long.c main.c) $(GNL)

SRCS_OBJ = ${SRCS_DIR:.c=.o}

GNL = $(addprefix gnl/, get_next_line.c get_next_line_utils.c)

FT_PRINTF = ./ft_printf/libftprintf.a

MINILIBX = ./minilibx-linux/libmlx.a

HEADER_DIR=./includes/

all: $(NAME)

$(NAME): $(SRCS_OBJ) $(MINILIBX) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(SRCS_OBJ) $(MINILIBX) $(FT_PRINTF) -lm -lX11 -lXext -g3 -o $(NAME)

$(MINILIBX) :
	make -C minilibx-linux/

$(FT_PRINTF) :
	make -C ft_printf/

clean :
	make -C ft_printf/ clean
	rm -f ${SRCS_OBJ}

fclean : clean
	make -C ft_printf/ fclean
	rm -f ${NAME}

re : fclean all