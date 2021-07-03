NAME = push_swap
B_NAME = checker
LIBS = libft/libft.a
SRC_DIR = srcs/
SRC_FILES = main.c operations.c mod_both_stacks.c list_check.c \
			push_swap_three.c push_swap_small.c init_min_max.c \
			make_sorted_list.c push_swap_large.c pivot_to_a.c \
			pivot_to_b.c partition_stack.c sort_to_a.c
B_SRC_FILES = main_bonus.c operations_bonus.c mod_both_stacks_bonus.c \
			  list_check_bonus.c create_list_bonus.c failed_exit_bonus.c
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
B_SRCS = $(addprefix $(SRC_DIR), $(B_SRC_FILES))
OBJS = $(SRCS:.c=.o)
B_OBJS = $(B_SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCS = -I includes

$(NAME): $(OBJS) includes/push_swap.h 
	make -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS) $(INCS) 

$(B_NAME): $(B_OBJS) includes/checker.h
	make -C libft
	$(CC) $(CFLAGS) -o $(B_NAME) $(B_OBJS) $(LIBS) $(INCS)

all: $(NAME)

bonus: $(B_NAME)

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
