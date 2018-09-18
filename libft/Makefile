# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antini <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/18 16:46:20 by antini            #+#    #+#              #
#    Updated: 2018/08/20 12:41:31 by antini           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NOC=\033[0m
GREEN=\033[32m
RED=\033[31m
YELL=\033[33m

NAME = libft.a

HEADER = libft.h

SRC = ft_strcpy.c ft_strncpy.c ft_isdigit.c ft_toupper.c ft_tolower.c \
	  ft_isalpha.c ft_isalnum.c ft_isprint.c ft_strlen.c ft_strdup.c \
	  ft_strstr.c ft_putchar.c ft_putstr.c ft_putchar_fd.c ft_putstr_fd.c \
	  ft_strcat.c ft_strncat.c ft_memcpy.c ft_bzero.c ft_memset.c \
	  ft_isascii.c ft_memccpy.c ft_strdel.c ft_strclr.c ft_memdel.c \
	  ft_memalloc.c ft_strnew.c ft_putendl.c ft_putendl_fd.c ft_striter.c \
	  ft_striteri.c ft_strcmp.c ft_strjoin.c ft_memcmp.c ft_strchr.c \
	  ft_strrchr.c ft_strmap.c ft_strsub.c ft_memchr.c ft_strequ.c \
	  ft_strncmp.c ft_strnequ.c ft_strmapi.c ft_memmove.c ft_isspace.c\
	  ft_strnstr.c ft_strlcat.c ft_strtrim.c ft_itoa.c ft_strsplit.c \
	  ft_putnbr_fd.c ft_putnbr.c ft_atoi.c get_next_line.c ft_max.c \
	  ft_min.c

OBJECT = $(SRC:.c=.o)
all: $(NAME)

$(NAME):
	gcc -c -Wall -Werror -Wextra $(SRC) -I $(HEADER)
	ar rc $(NAME) $(OBJECT)
	ranlib $(NAME)
	@echo "$(YELL)Make will now --------------------\t\t $(GREEN)COMPILE AND CREATE EXECUTABLE FILE $(NOC) "
	@echo "$(YELL)LIBFT ---------------------------------\t\t $(GREEN)libft.a  READY$(NOC)"

clean:
	@rm -rf *.o
	@echo "$(YELL)Make will now -------------------------------\t\t $(RED) REMOVE OBJECT FILES$(NOC)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(YELL)Make will now -------------------\t\t$(RED) REMOVE LIBRIARY $(NOC)"
	@echo "$(GREEN)----------------------------> ಠ_ಠ $(NOC)"
re: fclean all
	@echo "$(YELL)Make will now clean and ---------------\t\t $(GREEN) CREATE EXECUTABLE FILES$(NOC)"
	@echo "$(GREEN)----------------------------> ಠ_ಠ $(NOC)"
