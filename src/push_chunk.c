#include "../includes/push_swap.h"

void push_uppers(t_list **a_stack, t_list **b_stack, int mid_number, int *lesser_numbers_left)
{
	int current_number;

	current_number = *(int *)(*a_stack)->content;
	while (current_number < mid_number)
	{
		push_b(a_stack, b_stack);
		(*lesser_numbers_left)--;
		current_number = *(int *)(*a_stack)->content;
	}
}

void push_lowers(t_list **a_stack, t_list **b_stack, int mid_number, int *lesser_numbers_left)
{
	int current_number;
	t_list *last_element;

	last_element = ft_lstlast(*a_stack);
	current_number = *(int *)last_element->content;
	while (current_number < mid_number)
	{
		reverse_rotate_a(a_stack);
		push_b(a_stack, b_stack);
		(*lesser_numbers_left)--;
		last_element = ft_lstlast(*a_stack);
		current_number = *(int *)last_element->content;
	}
}

void push_chunk(t_list **a_stack, t_list **b_stack, int stack_size)
{
	int mid_number;
	int lesser_numbers_left;
	bool need_to_push_lowers;

	mid_number = find_mid_value(*a_stack, stack_size);
	lesser_numbers_left = stack_size / 2;
	need_to_push_lowers = true;
	while (lesser_numbers_left)
	{
		push_uppers(a_stack, b_stack, mid_number, &lesser_numbers_left);
		if (need_to_push_lowers)
		{
			push_lowers(a_stack, b_stack, mid_number, &lesser_numbers_left);
			need_to_push_lowers = false;
		}
		rotate_a(a_stack);
	}
	print_stack(*a_stack);
	print_stack(*b_stack);
}
