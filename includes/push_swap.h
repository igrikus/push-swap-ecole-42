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
void solve_two(t_list **a_stack);
int	find_mid_value(t_list *stack, int len);
int get_chunk_size(t_list *stack, int chunk);
void initialize_chunks(t_list **stack);
void insert_chunk_number_len(t_list **stack, int chunk, int len);
void pull_two_from_chunk(t_list **a_stack, t_list **b_stack);
bool is_chunk_already_sorted_asc(t_list *stack, int chunk);
bool is_chunk_already_sorted_desc(t_list *stack, int chunk);
void pull_whole_chunk_to_a(t_list **a_stack, t_list **b_stack, int chunk);

void pull_chunk_to_b(t_list **a_stack, t_list **b_stack, int *chunk, int pulled_chunk);
void pull_chunk_to_a(t_list **a_stack, t_list **b_stack, int *chunk, int pulled_chunk);

void print_stack(t_list *stack);
void print_chunk(t_list *stack, int chunk);

#endif
