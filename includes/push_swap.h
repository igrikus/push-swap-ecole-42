#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <limits.h>
#include <stdbool.h>
#include "../libft/libft.h"

#define ERROR_MESSAGE "Error\n"

bool is_arg_valid(char **argv);
void push(t_list **from, t_list **to);
void rotate(t_list **stack);
void reverse_rotate(t_list **stack);

#endif
