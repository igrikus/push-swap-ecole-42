#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include "../libft/libft.h"

# define OK_MESSAGE "OK"
# define KO_MESSAGE "KO"
# define ERROR_MESSAGE "Error"
# define PROMPT_MESSAGE "Yo man I need numbers in the INT range, no duplicates"

bool	fill_stack(t_list **a_stack, char **argv);

bool	is_arg_valid(char **argv);

void	push_a(t_list **a_stack, t_list **b_stack);
void	push_b(t_list **a_stack, t_list **b_stack);
void	swap_a(t_list **a_stack);
void	swap_b(t_list **b_stack);
void	swap_both(t_list **a_stack, t_list **b_stack);

void	rotate_a(t_list **a_stack);
void	rotate_b(t_list **b_stack);
void	rotate_both(t_list **a_stack, t_list **b_stack);
void	reverse_rotate_a(t_list **a_stack);
void	reverse_rotate_b(t_list **b_stack);
void	reverse_rotate_both(t_list **a_stack, t_list **b_stack);

void	solve(t_list **a_stack, t_list **b_stack);
void	solve_two(t_list **a_stack);
bool	is_stack_already_sorted(t_list *stack);

int		find_mid_value(t_list *stack, int len);

int		get_chunk_size(t_list *stack, int chunk);
void	initialize_chunks(t_list **stack);
void	insert_chunk_number(t_list **stack, int chunk, int len);
void	push_two_to_b(t_list **a_stack, t_list **b_stack);
void	pull_two_to_a(t_list **a_stack, t_list **b_stack);

void	push_chunk_to_b(t_list **a_stack, t_list **b_stack, int *chunk,
			int pushed_chunk);
void	push_chunk_to_a(t_list **a_stack, t_list **b_stack, int *chunk,
			int pushed_chunk);

#endif
