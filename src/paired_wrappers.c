#include "../includes/wrappers.h"

void	swap_both(t_list **a_stack, t_list **b_stack)
{
	swap(a_stack);
	swap(b_stack);
	ft_putendl_fd(SWAP_BOTH, STDOUT_FILENO);
}

void	rotate_both(t_list **a_stack, t_list **b_stack)
{
	rotate(a_stack);
	rotate(b_stack);
	ft_putendl_fd(ROTATE_BOTH, STDOUT_FILENO);
}

void	reverse_rotate_both(t_list **a_stack, t_list **b_stack)
{
	reverse_rotate(a_stack);
	reverse_rotate(b_stack);
	ft_putendl_fd(REVERSE_ROTATE_BOTH, STDOUT_FILENO);
}
