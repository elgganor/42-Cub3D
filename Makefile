NAME=Cub3D

INC=-I./inc
FLAGS=-Wall -Wextra -Werror

LIB_SRC=-L./lib/libft -lft -I/usr/local/include -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit
LIB_MAKE=-L./lib/libft -lft -L./lib/minilibx -lmlx -framework OpenGL -framework AppKit
LIB=$(LIB_SRC)

SRC_PATH=./src/
PARSING=parsing/check_args.c \
	parsing/read_map.c \
	parsing/get_cub_data.c \
	parsing/get_color_handle.c \
	parsing/check_cub_data.c \
	parsing/get_layout.c
MISC=misc/handle_errors.c \
	misc/free_functions.c \
	misc/init.c
WINDOW=window/draw.c
SRCS=$(PARSING) \
	$(MISC) \
	$(WINDOW) \
	cub3d.c \
	other.c

SRC=$(addprefix $(SRC_PATH), $(SRCS))

OBJ=$(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	@make -C lib/libft
ifeq ($(LIB), $(LIB_MAKE))
	@make -C lib/minilibx
endif
	@gcc $(FLAGS) $(INC) -o $(NAME) $(OBJ) $(LIB)

%.o: %.c
	@gcc $(FLAGS) $(INC) -o $@ -c $<

clean: $(OBJ)
	@make $@ -C lib/libft
ifeq ($(LIB), $(LIB_MAKE))
	@make $@ -C lib/minilibx
endif
	@rm -f $(OBJ)

fclean: clean
	@make $@ -C lib/libft
	@rm -f $(NAME)

re:
	@make fclean
	@make all

.PHONY: all clean fclean re