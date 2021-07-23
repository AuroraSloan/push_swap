PUSH_SWAP = push_swap
CHECKER = checker
LIBS = libft/libft.a
SRCS = srcs/push_swap/main.c srcs/push_swap/push_swap_three.c \
			srcs/push_swap/push_swap_small.c srcs/push_swap/init_min_max.c \
			srcs/push_swap/make_sorted_list.c srcs/push_swap/pivot_to_a.c \
			srcs/push_swap/push_swap_large.c srcs/push_swap/sort_to_a.c \
			srcs/push_swap/pivot_to_b.c srcs/push_swap/partition_stack.c \
			srcs/shared/operations.c srcs/shared/mod_both_stacks.c \
			srcs/shared/list_check.c srcs/shared/create_list.c
CHECKER_SRCS = srcs/checker/main.c srcs/checker/free_and_exit.c \
				srcs/shared/operations.c srcs/shared/mod_both_stacks.c \
				srcs/shared/list_check.c srcs/shared/create_list.c

OBJS = $(SRCS:.c=.o)
CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCS = -I includes

all: $(PUSH_SWAP) $(CHECKER)

$(PUSH_SWAP): $(OBJS) includes/push_swap.h 
	make -C libft
	$(CC) $(CFLAGS) -o $(PUSH_SWAP) $(OBJS) $(LIBS) $(INCS) 

$(CHECKER): $(CHECKER_OBJS) includes/checker.h
	$(CC) $(CFLAGS) -o $(CHECKER) $(CHECKER_OBJS) $(LIBS) $(INCS)

clean:
	rm -rf $(OBJS)
	rm -rf $(CHECKER_OBJS)
	make clean -C libft

fclean: clean
	rm -rf $(PUSH_SWAP)
	rm -rf $(CHECKER)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
