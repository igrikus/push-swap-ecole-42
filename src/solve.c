#include "../includes/push_swap.h"

static bool	is_stack_already_sorted(t_list *stack)
{
	int	current_number;
	int	next_number;

	while (stack->next)
	{
		current_number = *(int *) stack->content;
		next_number = *(int *) stack->next->content;
		if (current_number > next_number)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	solve_two(t_list **a_stack)
{
	int	first;
	int	second;

	first = *(int *)(*a_stack)->content;
	second = *(int *)(*a_stack)->next->content;
	if (first > second)
		swap_a(a_stack);
}

static void	solve_three(t_list **a_stack)
{
	int	first;
	int	second;
	int	third;

	first = *(int *)(*a_stack)->content;
	second = *(int *)(*a_stack)->next->content;
	third = *(int *)(*a_stack)->next->next->content;
	if (first < second && second < third)
		return ;
	else if (first > second && second < third && first < third)
		swap_a(a_stack);
	else if (first > second && first > third && second < third)
		rotate_a(a_stack);
	else if (first < second && first > third && second > third)
		reverse_rotate_a(a_stack);
	else if (first < second && second > third && first < third)
	{
		reverse_rotate_a(a_stack);
		swap_a(a_stack);
	}
	else if (first > second && second > third)
	{
		rotate_a(a_stack);
		swap_a(a_stack);
	}
}

static void	serious_solve(t_list **a_stack, t_list **b_stack)
{
	int	current_chunk;
	int	total_chunks;

	current_chunk = 0;
	total_chunks = 0;
	initialize_chunks(a_stack);
	while (!is_stack_already_sorted(*a_stack))
	{
		while (ft_lstsize(*a_stack) > 2)
		{
			pull_chunk_to_b(a_stack, b_stack, &current_chunk, total_chunks);
			if (ft_lstsize(*a_stack) > 2)
				total_chunks++;
		}
		solve_two(a_stack);
		current_chunk = total_chunks;
		while (ft_lstsize(*b_stack) > 0)
		{
			pull_chunk_to_a(a_stack, b_stack, &current_chunk, total_chunks);
			if (ft_lstsize(*b_stack) > 0)
				total_chunks++;
		}
		current_chunk = total_chunks;
	}
}

void	solve(t_list **a_stack, t_list **b_stack)
{
	int	a_stack_size;

	a_stack_size = ft_lstsize(*a_stack);
	if (a_stack_size == 1 || is_stack_already_sorted(*a_stack))
		return ;
	else if (a_stack_size == 2)
		solve_two(a_stack);
	else if (a_stack_size == 3)
		solve_three(a_stack);
	else
		serious_solve(a_stack, b_stack);
}
