# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antini <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/13 14:18:09 by antini            #+#    #+#              #
#    Updated: 2018/08/20 12:29:38 by antini           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN=\033[32m
NOC=\033[0m

NAME = fdf

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = main.c save_map.c ft_map_xyz.c ft_row.c \
ft_keyhook.c ft_draw_pixel.c ft_draw.c


OBJ = $(SRC:.c=.o)

$(NAME) :
	make -C libft/ fclean && make -C libft/
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) $(CFLAGS) $(OBJ) libft/libft.a -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit -o fdf
	@echo "$(GREEN)--------------------------------------------FDF  ready-----------> ಠ_ಠ $(NOC)"
all : $(NAME)

clean :
	$(RM) $(OBJ)
	make -C libft/ clean

fclean : clean
	$(RM) $(NAME)
	make -C libft/ fclean

re : fclean all

.PHONY : all clean fclean re
