PUSH_SWAP = push_swap
CHECKER = checker

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRC_DIR = src/
PUSH_SWAP_FILES = push_swap.c is_arg_valid.c fill_stack.c movements.c array_work.c \
				  solve.c push_swap_wrappers.c rotate_wrappers.c paired_wrappers.c \
			      push_chunk_to_a.c push_chunk_to_b.c chunk_helper.c

CHECKER_FILES = checker.c is_arg_valid.c fill_stack.c movements.c \
                push_swap_wrappers.c rotate_wrappers.c paired_wrappers.c

OBJ_DIR = obj/
PUSH_SWAP_OBJ_FILES = $(patsubst %.c,%.o,$(PUSH_SWAP_FILES))
PUSH_SWAP_OBJ = $(addprefix $(OBJ_DIR), $(PUSH_SWAP_OBJ_FILES))

CHECKER_OBJ_FILES = $(patsubst %.c,%.o,$(CHECKER_FILES))
CHECKER_OBJ = $(addprefix $(OBJ_DIR), $(CHECKER_OBJ_FILES))

LIBFT_DIR = libft

all: $(PUSH_SWAP) $(CHECKER)

$(PUSH_SWAP): $(PUSH_SWAP_OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	$(CC) -o $(PUSH_SWAP) $(PUSH_SWAP_OBJ) -L $(LIBFT_DIR) -lft

$(PUSH_SWAP_OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(CHECKER): $(CHECKER_OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	$(CC) -o $(CHECKER) $(CHECKER_OBJ) -L $(LIBFT_DIR) -lft

$(CHECKER_OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
ifeq ($(OS),Windows_NT)
	@del $(subst /,\,$(PUSH_SWAP_OBJ))
	@del $(subst /,\,$(CHECKER_OBJ))
else
	@rm -f $(PUSH_SWAP_OBJ) $(CHECKER_OBJ)
endif

fclean: clean
	@$(MAKE) fclean -C libft
ifeq ($(OS),Windows_NT)
	@del $(PUSH_SWAP).exe
	@del $(CHECKER).exe
else
	@rm -f $(PUSH_SWAP) $(CHECKER)
endif

re: fclean all

.PHONY: all clean fclean re
