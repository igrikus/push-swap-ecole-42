#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <limits.h>
#include <stdbool.h>
#include "../libft/libft.h"

#define ERROR_MESSAGE "Error"

bool is_arg_valid(char **argv);
void push_a(t_list **a_stack, t_list **b_stack);
void push_b(t_list **a_stack, t_list **b_stack);
void swap_a(t_list **a_stack);
void swap_b(t_list **b_stack);
void rotate_a(t_list **a_stack);
void rotate_b(t_list **b_stack);
void reverse_rotate_a(t_list **a_stack);
void reverse_rotate_b(t_list **b_stack);
void solve(t_list **a_stack, t_list **b_stack);
int find_min_number_position(t_list *stack);
void rotate_min_to_top(t_list **stack, int stack_size);

#endif
