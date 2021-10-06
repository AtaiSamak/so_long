CC = gcc
FLAG = -Wall -Wextra -Werror
REQUIREMENTS = -Lmlx -lmlx -framework OpenGL -framework AppKit

MLX = mlx
MLX_LIB = libmlx.a
NAME = so_long
LIBRARY = so_long.a

SRCS = 	main.c \
		setSettings.c \
		writeMap.c \
		checkers.c \
		miniFunctions.c \
		mainFunctions.c \


OBJS = $(SRCS:.c=.o)

all: $(NAME) $(LIBRARY)

$(LIBRARY): $(OBJS)
	@ar rc $(LIBRARY) $(OBJS)
	@echo "$(LIBRARY) created"
	@ranlib $(LIBRARY)
	@echo "$(LIBRARY) indexed"

$(NAME): $(LIBRARY)
	@make -C $(MLX)
	@$(CC) $(REQUIREMENTS) $(LIBRARY) $(MLX)/$(MLX_LIB) -o $(NAME)
	@echo "$(NAME) created"


%.o: %.c
	@$(CC) $(FLAG) -Imlx -c $^ -o $@

clean:
	@make -C $(MLX) clean
	@echo "MLX deleted"
	@rm -f $(OBJS)
	@echo "OBJS deleted"

fclean: clean
	@make -C $(MLX) clean
	@echo "MLX deleted"
	@rm -f $(NAME)
	@echo "$(NAME) deleted"
	@rm -f $(LIBRARY)
	@echo "$(LIBRARY) deleted"


re: fclean all

.PHONY: all clean fclean re
