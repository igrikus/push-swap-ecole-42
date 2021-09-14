NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRC_DIR = src/
SRC_FILES = push_swap.c is_arg_valid.c
SRC = $(addprefix $(SRC_DIR),$(SRC_FILES))

OBJ_DIR = obj/
OBJ_FILES = $(patsubst %.c,%.o,$(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

LIBFT_DIR = libft

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	$(CC) -o $(NAME) $(OBJ) -L $(LIBFT_DIR) -lft

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@make clean -C $(LIBFT_DIR)
ifeq ($(OS),Windows_NT)
	@del $(subst /,\,$(OBJ))
else
	@rm -f $(OBJ)
endif

fclean: clean
	@make fclean -C libft
ifeq ($(OS),Windows_NT)
	@del $(NAME).exe
else
	@rm -f $(NAME)
endif

re: fclean all

.PHONY: all clean fclean re
