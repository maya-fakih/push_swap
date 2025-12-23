NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = push_swap.c swap_ops.c rotate_ops.c rev_rotate_ops.c utils.c
OBJ = push_swap.o operations.o utils.o
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I $(LIBFT_DIR)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJ) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
