#include "../includes/push_swap.h"

void	swap_both(t_list **a_stack, t_list **b_stack)
{
	swap(a_stack);
	swap(b_stack);
}

void	rotate_both(t_list **a_stack, t_list **b_stack)
{
	rotate(a_stack);
	rotate(b_stack);
}

void	reverse_rotate_both(t_list **a_stack, t_list **b_stack)
{
	reverse_rotate(a_stack);
	reverse_rotate(b_stack);
}
