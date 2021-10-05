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
int	find_mid_value(t_list *stack, int len);
int get_chunk_len(t_list *stack, int chunk);
void push_chunk(t_list **a_stack, t_list **b_stack, int stack_size);
void pull_chunk(t_list **a_stack, t_list **b_stack, int chunk, int chunk_size);
void pull_last_chunk(t_list **a_stack, t_list **b_stack, int chunk, int chunk_size);
void pull_two_from_chunk(t_list **a_stack, t_list **b_stack);
void print_stack(t_list *stack);

#endif
