#include "../includes/push_swap.h"

static void solve_two(t_list *a_stack)
{
	int first;
	int second;

	first = *(int *) a_stack->content;
	second = *(int *) a_stack->next->content;

	if (first > second)
		swap_a(a_stack);
}

static void solve_three(t_list *a_stack)
{
	int first;
	int second;
	int third;

	first = *(int *) a_stack->content;
	second = *(int *) a_stack->next->content;
	third = *(int *) a_stack->next->next->content;

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

static void serious_solve(t_list *a_stack, t_list *b_stack)
{
	(void) a_stack;
	(void) b_stack;
}

void solve(t_list *a_stack, t_list *b_stack)
{
	int a_stack_size;

	a_stack_size = ft_lstsize(a_stack);
	if (a_stack_size == 1)
		return;
	else if (a_stack_size == 2)
		solve_two(a_stack);
	else if (a_stack_size == 3)
		solve_three(a_stack);
	else
		serious_solve(a_stack, b_stack);
}
