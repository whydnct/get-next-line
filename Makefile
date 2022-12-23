# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperez-m <aperez-m@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 13:31:05 by aperez-m          #+#    #+#              #
#    Updated: 2022/12/23 22:59:26 by aperez-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = test

SRC =	\
		get_next_line_utils.c \
		main.c

OBJ = $(SRC:.c=.o) 

all: $(NAME)

$(NAME): 
	@$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, bonus
