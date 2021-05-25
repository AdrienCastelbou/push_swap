NAME=	push_swap
SRCS=	main.c dlist.c
OBJS=	$(addprefix srcs/, $(SRCS:.c=.o))
CC=		gcc
CFLAGS=	-Wextra -Wall -Werror
LIBFT_DIR= libft
HEADER=	-I includes -I $(LIBFT_DIR)
LDFLAGS=	-L $(LIBFT_DIR)
LIBS=	-lft

.c.o:
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $(<:.c=.o)
$(NAME):	$(OBJS)
	make bonus -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $(NAME) $(LIBS)
all: $(NAME)
clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)
re: clean all
.PHONY: all, clean, fclean, re


