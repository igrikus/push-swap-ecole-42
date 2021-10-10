PUSH_SWAP = push_swap
CHECKER = checker

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRC_DIR = src/
PUSH_SWAP_FILES = push_swap.c is_arg_valid.c movements.c array_work.c solve.c \
			push_swap_wrappers.c rotate_wrappers.c paired_wrappers.c \
			push_chunk_to_a.c push_chunk_to_b.c chunk_helper.c

OBJ_DIR = obj/
OBJ_FILES = $(patsubst %.c,%.o,$(PUSH_SWAP_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

LIBFT_DIR = libft

all: $(PUSH_SWAP)

$(PUSH_SWAP): $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	$(CC) -o $(PUSH_SWAP) $(OBJ) -L $(LIBFT_DIR) -lft

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
ifeq ($(OS),Windows_NT)
	@del $(subst /,\,$(OBJ))
else
	@rm -f $(OBJ)
endif

fclean: clean
	@$(MAKE) fclean -C libft
ifeq ($(OS),Windows_NT)
	@del $(PUSH_SWAP).exe
else
	@rm -f $(PUSH_SWAP)
endif

re: fclean all

.PHONY: all clean fclean re
