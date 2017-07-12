# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbert <jbert@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/13 20:16:24 by jbert             #+#    #+#              #
#    Updated: 2017/02/06 20:02:41 by jbert            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=lemipc

SRC=lemipc.c lemipc1.c lemipc2.c lemipc3.c lemipc4.c main.c

OBJ=lemipc.o lemipc1.o lemipc2.o lemipc3.o lemipc4.o main.o

$(NAME):
			gcc -c $(SRC)
			gcc -o $(NAME) $(OBJ) libftprintf/libftprintf.a

all: $(NAME)

clean:
		rm -f $(OBJ)

fclean:
		rm -f $(OBJ) $(NAME)

re: fclean all
