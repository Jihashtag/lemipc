# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbert <jbert@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/21 04:09:22 by jbert             #+#    #+#              #
#    Updated: 2015/06/05 12:08:44 by jbert            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRC	=	libft/ft_memccpy.c	libft/ft_putstr.c	libft/ft_strdup.c	libft/ft_strrchr.c	libft/ft_memcpy.c	libft/ft_putstr_fd.c	libft/ft_strlcat.c	libft/ft_strstr.c	libft/ft_bzero.c	libft/ft_memset.c	libft/ft_isprint.c	libft/ft_strlen.c	libft/ft_tolower.c	libft/ft_isalnum.c	libft/ft_putchar.c	libft/ft_strcat.c	libft/ft_strncat.c	libft/ft_toupper.c	libft/ft_isalpha.c	libft/ft_putchar_fd.c	libft/ft_strchr.c	libft/ft_strncmp.c	libft/ft_isascii.c	libft/ft_putendl.c	libft/ft_strcmp.c	libft/ft_strncpy.c	libft/ft_isdigit.c	libft/ft_putendl_fd.c	libft/ft_strcpy.c	libft/ft_strnstr.c	libft/ft_memmove.c	libft/ft_atoi.c	libft/ft_strlcat.c	libft/ft_memchr.c	libft/ft_memcmp.c	libft/ft_strclr.c	libft/ft_striter.c	libft/ft_striteri.c	libft/ft_strmap.c	libft/ft_strmapi.c	libft/ft_strequ.c	libft/ft_strnequ.c	libft/ft_strsplit.c	libft/ft_itoa.c	libft/ft_putnbr.c	libft/ft_putnbr_fd.c	libft/ft_memdel.c	libft/ft_strnew.c	libft/ft_memalloc.c	libft/ft_strdel.c	libft/ft_strjoin.c	libft/ft_strtrim.c	libft/get_next_line.c	printf.c	printf2.c	printf3.c	printf4.c	printf5.c	printf6.c	printf7.c	printf8.c	printf9.c	printf10.c

OBJ	=	./ft_memccpy.o	./ft_putstr.o	./ft_strdup.o	./ft_strrchr.o	./ft_memcpy.o	./ft_putstr_fd.o	./ft_strlcat.o	./ft_strstr.o	./ft_bzero.o	./ft_memset.o	./ft_isprint.o	./ft_strlen.o	./ft_tolower.o	./ft_isalnum.o	./ft_putchar.o	./ft_strcat.o	./ft_strncat.o	./ft_toupper.o	./ft_isalpha.o	./ft_putchar_fd.o	./ft_strchr.o	./ft_strncmp.o	./ft_isascii.o	./ft_putendl.o	./ft_strcmp.o	./ft_strncpy.o	./ft_isdigit.o	./ft_putendl_fd.o	./ft_strcpy.o	./ft_strnstr.o	./ft_memmove.o	./ft_atoi.o	./ft_strlcat.o	./ft_memchr.o	./ft_memcmp.o	./ft_strclr.o	./ft_striter.o	./ft_striteri.o	./ft_strmap.o	./ft_strmapi.o	./ft_strequ.o	./ft_strnequ.o	./ft_strsplit.o	./ft_itoa.o	./ft_putnbr.o	./ft_putnbr_fd.o	./ft_memdel.o	./ft_strnew.o	./ft_memalloc.o	./ft_strdel.o	./ft_strjoin.o	./ft_strtrim.o	./get_next_line.o	printf.o	printf2.o	printf3.o	printf4.o	printf5.o	printf6.o	printf7.o	printf8.o	printf9.o	printf10.o

$(NAME):
		@gcc -c $(SRC) -Wall -Wextra -Werror -g3 -I ./
		@ar rc $(NAME) $(OBJ)

all: $(NAME)

clean:
		@rm -f $(OBJ)

fclean:
		@rm -f $(OBJ) libftprintf.a

re : fclean all

.PHONY: NAME all clean re
