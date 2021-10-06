#include "../includes/push_swap.h"

static void swap_two(t_list **b_stack)
{
	int first;
	int second;

	first = *(int *) (*b_stack)->content;
	second = *(int *) (*b_stack)->next->content;

	if (first < second)
		swap_b(b_stack);
}

static void pull_two(t_list **a_stack, t_list **b_stack)
{
	swap_two(b_stack);
	push_a(a_stack, b_stack);
	push_a(a_stack, b_stack);
}

static void pull_uppers(t_list **a_stack, t_list **b_stack, int mid_number, int *bigger_numbers_left)
{
	int current_number;

	current_number = *(int *) (*b_stack)->content;
	while (current_number > mid_number)
	{
		push_a(a_stack, b_stack);
		(*bigger_numbers_left)--;
		current_number = *(int *) (*b_stack)->content;
	}
}

static void pull_lowers(t_list **a_stack, t_list **b_stack, int mid_number, int *bigger_numbers_left)
{
	int current_number;

	current_number = *(int *) ft_lstlast(*b_stack)->content;
	while (current_number > mid_number)
	{
		reverse_rotate_b(b_stack);
		push_a(a_stack, b_stack);
		(*bigger_numbers_left)--;
		current_number = *(int *) ft_lstlast(*b_stack)->content;
	}
}

void pull_chunk_desc(t_list **a_stack, t_list **b_stack, int chunk, int chunk_size)
{
	int mid_number;
	int bigger_numbers_left;
	int rb_count;

	if (chunk_size == 1)
		push_a(a_stack, b_stack);
	else if (chunk_size == 2)
		pull_two(a_stack, b_stack);
	else
	{
		rb_count = 0;
		mid_number = find_mid_value(*b_stack, chunk_size);
		bigger_numbers_left = chunk_size / 2;
		while (bigger_numbers_left)
		{
			pull_uppers(a_stack, b_stack, mid_number, &bigger_numbers_left);
			if (bigger_numbers_left)
			{
				rotate_b(b_stack);
				rb_count++;
			}
		}
		while (rb_count-- > 0)
			reverse_rotate_b(b_stack);
		chunk_size = get_chunk_size(*b_stack, chunk);
		pull_chunk_desc(a_stack, b_stack, chunk, chunk_size);
	}
}

void pull_last_chunk_desc(t_list **a_stack, t_list **b_stack, int chunk, int chunk_size)
{
	int mid_number;
	int bigger_numbers_left;
	bool need_to_pull_lowers;

	if (chunk_size == 1 || is_chunk_already_sorted_desc(*b_stack, chunk))
		pull_whole_chunk_to_a(a_stack, b_stack, chunk);
	else if (chunk_size == 2)
		pull_two(a_stack, b_stack);
	else
	{
		mid_number = find_mid_value(*b_stack, chunk_size);
		bigger_numbers_left = chunk_size / 2;
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
		chunk_size = get_chunk_size(*b_stack, chunk);
		pull_last_chunk_desc(a_stack, b_stack, chunk, chunk_size);
	}
}
