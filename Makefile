# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cimogene <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/04 10:46:54 by cimogene          #+#    #+#              #
#    Updated: 2019/10/14 19:42:21 by nslughor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = checker

NAME2 = push_swap

SRC1 = instructions_1.c instructions_2.c \
		checker.c stack_a_func.c \
		stack_b_func.c utils_1.c utils_2.c \
		checker_main.c

SRC2 = instructions_1.c instructions_2.c \
		checker.c stack_a_func.c \
		stack_b_func.c utils_1.c utils_2.c \
		push_swap_main.c

OBJ1 = $(subst .c,.o,$(SRC1))

OBJ2 = $(subst .c,.o,$(SRC2))

all: $(NAME1) $(NAME2)

$(NAME1): lib $(OBJ1)
	gcc -Wall -Werror -Wextra $(OBJ1) -o $(NAME1) -L./libft -lft

$(NAME2): lib $(OBJ2)
	gcc -Wall -Werror -Wextra $(OBJ2) -o $(NAME2) -L./libft -lft

lib:
	(cd libft; make)

%.o: %.c push_swap.h
	gcc -Wall -Werror -Wextra -o $@ -c $<

clean:
	rm -f $(OBJ1) $(OBJ2)
	(cd libft; make clean)

fclean: 
	rm -f $(OBJ1) $(OBJ2)
	rm -f $(NAME1) $(NAME2)
	(cd libft; make fclean)

re: fclean all

.PHONY: all lib clean fclean re
