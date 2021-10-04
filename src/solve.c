#include "../includes/push_swap.h"

bool is_stack_already_sorted(t_list *stack)
{
	int current_number;
	int next_number;

	while (stack->next)
	{
		current_number = *(int *) stack->content;
		next_number = *(int *) stack->next->content;
		if (current_number > next_number)
			return false;
		stack = stack->next;
	}
	return true;
}

static void solve_two(t_list **a_stack)
{
	int first;
	int second;

	first = *(int *) (*a_stack)->content;
	second = *(int *) (*a_stack)->next->content;

	if (first > second)
		swap_a(a_stack);
}

static void solve_three(t_list **a_stack)
{
	int first;
	int second;
	int third;

	first = *(int *) (*a_stack)->content;
	second = *(int *) (*a_stack)->next->content;
	third = *(int *) (*a_stack)->next->next->content;

	if (first < second && second < third)
		return;
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
	} else if (first > second && second > third)
	{
		rotate_a(a_stack);
		swap_a(a_stack);
	}
}

static void serious_solve(t_list **a_stack, t_list **b_stack, int stack_size)
{
	int counter;
	int half_size;
	int current_size;
	int min_num_pos;

	counter = 0;
	current_size = stack_size;
	while (counter < stack_size)
	{
		half_size = current_size / 2;
		min_num_pos = find_min_number_position(*a_stack);
		rotate_min_to_top(a_stack, min_num_pos, current_size, half_size);
		push_b(a_stack, b_stack);
		current_size = ft_lstsize(*a_stack);
		counter++;
	}
	counter = 0;
	while (counter < stack_size)
	{
		push_a(a_stack, b_stack);
		counter++;
	}
}

void solve(t_list **a_stack, t_list **b_stack)
{
	int a_stack_size;

	a_stack_size = ft_lstsize(*a_stack);
	if (a_stack_size == 1 || is_stack_already_sorted(*a_stack))
		return;
	else if (a_stack_size == 2)
		solve_two(a_stack);
	else if (a_stack_size == 3)
		solve_three(a_stack);
	else
		serious_solve(a_stack, b_stack, a_stack_size);
}
