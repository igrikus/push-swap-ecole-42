NAME    = libft.a

SOURCE    = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_strlen.c\
			ft_memchr.c ft_memcmp.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c\
			ft_isprint.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c\
			ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_strdup.c ft_calloc.c ft_atoi.c\
			ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c\
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strcmp.c\
			ft_atoll.c get_next_line.c get_next_line_utils.c

SOURCE_BONUS   = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
				ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_lstsort.c

OBJ = $(patsubst %.c,%.o,$(SOURCE))
OBJ_BONUS = $(patsubst %.c,%.o,$(SOURCE_BONUS))

D_FILES = $(patsubst %.c,%.d,$(SOURCE) $(SOURCE_BONUS))

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_BONUS)
	ar rcs $(NAME) $?

%.o: %.c
	gcc $(FLAGS) -c $< -o $@ -MD

include $(wildcard $(D_FILES))

clean:
ifeq ($(OS), Windows_NT)
	@del $(OBJ) $(OBJ_BONUS) $(D_FILES)
else
	@rm -f $(OBJ) $(OBJ_BONUS) $(D_FILES)
endif

fclean: clean
ifeq ($(OS),Windows_NT)
	@del $(NAME)
else
	@rm -f $(NAME)
endif

re: fclean all

.PHONY: all clean fclean re bonus
