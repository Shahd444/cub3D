CC = cc
CFLAGS = -Wall -Werror -Wextra -g
NAME = cub3D
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_PATH = ../minilibx-linux
MLX_LIB = -L$(MLX_PATH) -lmlx -lXext -lX11

SRC = main.c\
	init_map/map.c\
	clean.c\
	validation/valid.c\
	hooks/keypress.c\
	init_map/init.c\
	raycasting/raycasting.c\
	raycasting/raycasting_utils.c\
	raycasting/raycasting_utils2.c\
	raycasting/raycasting_utils3.c\
	hooks/moving.c\
	raycasting/player_dir.c\
	validation/valid_color.c\
	init_map/minimap.c\
 	validation/valid_utils.c \
	raycasting/load_tex.c\
	hooks/door.c\

OBJ = $(SRC:%.c=objs/%.o)

all: $(NAME)

libft:
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME) : $(OBJ) | libft
	@$(CC) $(CFLAGS) -lm $^ -o $(NAME) $(LIBFT) $(MLX_LIB)

objs/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf objs
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re libft mlx
