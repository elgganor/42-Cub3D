NAME=Cub3D

INC=-I./inc
FLAGSD=-Wall -Wextra -Werror -fsanitize=address
FLAGS=-Wall -Wextra -Werror

LIB_LINUX=-L./libft -lft -I/usr/local/include -L/usr/local/lib -lmlx -L/usr/include -lm -lbsd -lX11 -lXext
LIB_MAC=-L./libft -lft -I/usr/local/include -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit
LIB=$(LIB_MAC)

SRC_PATH=./src/
PARSING=parsing/check_args.c \
	parsing/read_map.c \
	parsing/get_cub_data.c \
	parsing/get_color_handle.c \
	parsing/check_cub_data.c \
	parsing/get_layout.c \
	parsing/check_layout.c \
	parsing/get_textures.c
UTILS=utils/handle_errors.c \
	utils/free_functions.c \
	utils/init.c \
	utils/init2.c \
	utils/display.c \
	utils/set_position.c \
	utils/clear.c \
	utils/utils.c
ENGINE=engine/camera.c \
	engine/digital_differential_analyser.c \
	engine/player.c \
	engine/raycasting.c \
	engine/sprite.c
EVENT=event_manager/key_event_handler.c \
	event_manager/main_loop.c \
	event_manager/window_destroy.c
RENDER=render/draw.c \
	render/texture.c \
	render/sprite.c \
	render/bitmap.c
SRCS=$(PARSING) \
	$(UTILS) \
	$(ENGINE) \
	$(EVENT) \
	$(RENDER) \
	cub3d.c

SRC=$(addprefix $(SRC_PATH), $(SRCS))

OBJ=$(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@gcc $(FLAGSD) $(INC) -o $(NAME) $(OBJ) $(LIB)

%.o: %.c
	@gcc $(FLAGS) $(INC) -o $@ -c $<

clean: $(OBJ)
	@make $@ -C libft
	@rm -f $(OBJ)

fclean: clean
	@make $@ -C libft
	@rm -f $(NAME)

re:
	@make fclean
	@make all

.PHONY: all clean fclean re