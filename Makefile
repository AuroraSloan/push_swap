# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jthompso <jthompso@student.42tokyo.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/27 18:46:49 by jthompso          #+#    #+#              #
#    Updated: 2021/06/09 16:47:45 by jthompso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
B_NAME = checker
LIBS = libft/libft.a
SRC_DIR = srcs/
SRC_FILES = main.c
B_SRC_FILES = main_bonus.c
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
B_SRCS = $(addprefix $(SRC_DIR), $(B_SRC_FILES))
OBJS = $(SRCS:.c=.o)
B_OBJS = $(B_SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCS = -I includes

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS) $(INCS) 

all: $(NAME)

bonus: $(B_OBJS)
	make -C libft
	$(CC) $(CFLAGS) -o $(B_NAME) $(B_OBJS) $(LIBS) $(INCS)

clean:
	rm -rf $(OBJS)
	rm -rf $(B_OBJS)
	make clean -C libft

fclean: clean
	rm -rf $(NAME)
	rm -rf $(B_NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re bonus
