NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Iheaders

VALGRIND = valgrind --leak-check=full --show-leak-kinds=all

SOURCE = game_main/*.c

GNL = gnl/*.c

PRINTF = printf/*.c

LIBFT = libft/*.c

LIBRARY := -Lminilibx -lmlx -lX11 -lXext -lXrandr

MINILIBX := minilibx/

all:
	make -C $(MINILIBX)
	$(CC) $(CFLAGS) $(SOURCE) $(LIBFT) $(GNL) $(PRINTF) $(LIBRARY) -o $(NAME)

clean:

fclean: clean
		make clean -C $(MINILIBX)
		rm -rf $(NAME)

re: fclean all

valgrind: $(NAME)
	$(VALGRIND) ./$(NAME) maps/simplest.ber

