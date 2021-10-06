#include "../includes/wrappers.h"

void push_a(t_list **a_stack, t_list **b_stack)
{
	push(b_stack, a_stack);
	ft_putendl_fd(PUSH_A, STDOUT_FILENO);
}

void push_b(t_list **a_stack, t_list **b_stack)
{
	push(a_stack, b_stack);
	ft_putendl_fd(PUSH_B, STDOUT_FILENO);
}

void swap_a(t_list **a_stack)
{
	swap(a_stack);
	ft_putendl_fd(SWAP_A, STDOUT_FILENO);
}

void swap_b(t_list **b_stack)
{
	swap(b_stack);
	ft_putendl_fd(SWAP_B, STDOUT_FILENO);
}
