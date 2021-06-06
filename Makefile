# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jthompso <jthompso@student.42tokyo.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/27 18:46:49 by jthompso          #+#    #+#              #
#    Updated: 2021/06/03 14:16:15 by jthompso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBS = libft/libft.a
SRC_DIR = srcs/
SRC_FILES = main.c
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCS = -I includes

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	#$(CC) $(CFLAGS) $(INCS) $(LIBS) $(OBJS) -o $(NAME)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS) $(INCS) 
clean:
	rm $(OBJS)
	make clean -C libft

fclean: clean
	rm $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
