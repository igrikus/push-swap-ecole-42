#include "../includes/push_swap.h"

int get_chunk_len(t_list *stack, int chunk)
{
	int len;

	len = 0;
	while (stack && stack->chunk == chunk)
	{
		len++;
		stack = stack->next;
	}
	return len;
}

void swap_two_in_chunk(t_list **b_stack)
{
	int first;
	int second;

	first = *(int *)(*b_stack)->content;
	second = *(int *)(*b_stack)->next->content;

	if (first < second)
		swap_b(b_stack);
}

void pull_two_from_chunk(t_list **a_stack, t_list **b_stack)
{
	int first;
	int second;

	first = *(int *)(*b_stack)->content;
	second = *(int *)(*b_stack)->next->content;

	if (first < second)
		swap_b(b_stack);
	push_a(a_stack, b_stack);
	push_a(a_stack, b_stack);
}

static void pull_uppers(t_list **a_stack, t_list **b_stack, int mid_number, int *bigger_numbers_left)
{
	int current_number;

	current_number = *(int *)(*b_stack)->content;
	while (current_number > mid_number)
	{
		push_a(a_stack, b_stack);
		(*bigger_numbers_left)--;
		current_number = *(int *)(*b_stack)->content;
	}
}

static void pull_lowers(t_list **a_stack, t_list **b_stack, int mid_number, int *bigger_numbers_left)
{
	int current_number;
	t_list *last_element;

	last_element = ft_lstlast(*b_stack);
	current_number = *(int *)last_element->content;
	while (current_number > mid_number)
	{
		reverse_rotate_b(b_stack);
		push_a(a_stack, b_stack);
		(*bigger_numbers_left)--;
		last_element = ft_lstlast(*b_stack);
		current_number = *(int *)last_element->content;
	}
}

void pull_chunk(t_list **a_stack, t_list **b_stack, int chunk, int chunk_size)
{
	int mid_number;
	int bigger_numbers_left;
	int ra_count;

	if (chunk_size == 1)
	{
		push_a(a_stack, b_stack);
		return;
	} else if (chunk_size == 2)
	{
		pull_two_from_chunk(a_stack, b_stack);
		return;
	}
	swap_two_in_chunk(b_stack);
	if (is_chunk_already_sorted(*b_stack, chunk))
	{
		while (*b_stack && (*b_stack)->chunk == chunk)
			push_a(a_stack, b_stack);
		return;
	}
	ra_count = 0;
	mid_number = find_mid_value(*b_stack, chunk_size);
	if (chunk_size % 2 == 1)
		bigger_numbers_left = chunk_size / 2;
	else
		bigger_numbers_left = (chunk_size / 2) - 1;
	while (bigger_numbers_left)
	{
		print_chunk(*b_stack, chunk);
		pull_uppers(a_stack, b_stack, mid_number, &bigger_numbers_left);
		if (bigger_numbers_left)
		{
			rotate_b(b_stack);
			ra_count++;
		}
	}
	while (ra_count > 0)
	{
		reverse_rotate_b(b_stack);
		ra_count--;
	}
	chunk_size = get_chunk_len(*b_stack, chunk);
	pull_chunk(a_stack, b_stack, chunk, chunk_size);
}

void pull_last_chunk(t_list **a_stack, t_list **b_stack, int chunk, int chunk_size)
{
	int mid_number;
	int bigger_numbers_left;
	bool need_to_pull_lowers;

	if (chunk_size == 1)
	{
		push_a(a_stack, b_stack);
		return;
	} else if (chunk_size == 2)
	{
		pull_two_from_chunk(a_stack, b_stack);
		return;
	}
	swap_two_in_chunk(b_stack);
	if (is_chunk_already_sorted(*b_stack, chunk))
	{
		while (*b_stack && (*b_stack)->chunk == chunk)
			push_a(a_stack, b_stack);
		return;
	}
	mid_number = find_mid_value(*b_stack, chunk_size);
	if (chunk_size % 2 == 1)
		bigger_numbers_left = chunk_size / 2;
	else
		bigger_numbers_left = (chunk_size / 2) - 1;
	need_to_pull_lowers = true;
	while (bigger_numbers_left)
	{
		pull_uppers(a_stack, b_stack, mid_number, &bigger_numbers_left);
		if (need_to_pull_lowers)
		{
			pull_lowers(a_stack, b_stack, mid_number, &bigger_numbers_left);
			need_to_pull_lowers = false;
		}
		if (bigger_numbers_left)
			rotate_b(b_stack);
	}
	chunk_size = get_chunk_len(*b_stack, chunk);
	pull_last_chunk(a_stack, b_stack, chunk, chunk_size);
}
