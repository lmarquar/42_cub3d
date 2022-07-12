CC				:= gcc
CFLAGS			:= -Wall -Werror -Wextra -g
PARSER_DIR		:= parser/
PARSER_FILES	:= parser.c layout_load.c layout_checker.c texture_load.c texture_checker.c texture_utility.c
PARSER			:= $(addprefix $(PARSER_DIR),$(PARSER_FILES))
GNL_FILES		:= get_next_line.c get_next_line_utils.c gnl_no_nl.c
GNL				:= $(addprefix gnl/,$(GNL_FILES))
SRC_FILES		:=	cub3d.c init.c init2.c minimap.c hooks.c free_data.c move.c move_direction.c $(PARSER) $(GNL) \
					ray.c get_hori_len.c get_perp_len.c	square_angles.c texture.c color_pixels.c utility.c
SRC_DIR			:= srcs/
SRC				:= $(addprefix $(SRC_DIR),$(SRC_FILES))
INCLUDE_DIR		:= include/
NAME			:= cub3d
LIBFT_DIR		:= $(INCLUDE_DIR)libft/
LIBFT			:= $(LIBFT_DIR)libft.a
TEST_DIR		:= tester/
TEST_FILES		:= tester.c helper.c
TEST_SRC		:= $(addprefix $(TEST_DIR),$(TEST_FILES)) $(filter-out $(SRC_DIR)cub3d.c, $(SRC))
TEST_NAME		:= cub3d_tester

ifeq ($(shell uname -s),Darwin)
	LBMLX	:= $(INCLUDE_DIR)mlx/libmlx.a
	LIBS	:= -L /usr/X11/lib -lXext -lX11
else
	LBMLX	:= $(INCLUDE_DIR)mlx/libmlx_Linux.a
	LIBS	:= -lXext -lX11 -lm
endif

all: $(NAME)

test: $(TEST_NAME)

re: fclean $(NAME)

$(NAME): $(LIBFT)
	$(CC) $(CFLAGS) $(SRC) $(LBMLX) $(LIBS) $(LIBFT) -o $@

$(TEST_NAME): $(LIBFT)
	$(CC) $(CFLAGS) $(TEST_SRC) $(LBMLX) $(LIBS) $(LIBFT) -o $@

valgrindcheck: fclean $(LIBFT)
	$(CC) $(CFLAGS) $(SRC) $(LBMLX) $(LIBS) $(LIBFT) -o $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) testmap.cub

leakcheck:		fclean $(LIBFT)
	$(CC) $(CFLAGS) $(SRC) $(LBMLX) $(LIBS) $(LIBFT) -o $(NAME)
	leaks --atExit -- ./$(NAME) testmap.cub

normcheck:
	norminette $(SRC_DIR) $(LIBFT_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	rm -rfd $(NAME).dSYM
	rm -rfd $(TEST_NAME).dSYM

fclean:
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)
	rm -rfd $(NAME).dSYM
	rm -f $(TEST_NAME)
	rm -rfd $(TEST_NAME).dSYM
