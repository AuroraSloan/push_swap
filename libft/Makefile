NAME = libft.a
SRCS = ft_strlcpy.c ft_strlen.c ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c \
	ft_isalpha.c ft_atoi.c ft_strncmp.c ft_strnstr.c ft_strlcat.c \
	ft_toupper.c ft_isprint.c ft_isascii.c ft_isalnum.c ft_isdigit.c \
	ft_strjoin.c ft_substr.c ft_calloc.c ft_strdup.c ft_tolower.c \
	ft_memcpy.c ft_bzero.c ft_memset.c ft_strtrim.c ft_putchar_fd.c \
	ft_strchr.c ft_memcmp.c ft_memchr.c ft_memmove.c ft_memccpy.c \
	ft_itoa.c ft_split.c ft_strmapi.c ft_strrchr.c ft_lstadd_back.c \
	ft_lstlast.c ft_lstsize.c ft_lstadd_front.c ft_lstmap.c ft_lstiter.c \
	ft_lstclear.c ft_lstdelone.c ft_lstnew.c ft_isspace.c ft_numlen.c \
	ft_putnbr.c get_next_line.c ft_find_char.c ft_free.c ft_lstprint.c \
	ft_lstprint_int.c ft_putchar.c ft_putendl.c ft_putstr.c ft_strldup.c \
	ft_failed_exit.c
HEADER = libft.h
OBJS = $(SRCS:.c=.o)
CC = gcc 
CFLAGS = -Wall -Werror -Wextra

$(NAME): $(OBJS) $(HEADER)
	ar rc $(NAME) $(OBJS)	

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all 

.PHONY: all clean fclean re bonus
