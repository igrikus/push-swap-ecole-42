#include "../includes/push_swap.h"

static void swap_two(t_list **a_stack)
{
	int first;
	int second;

	first = *(int *) (*a_stack)->content;
	second = *(int *) (*a_stack)->next->content;

	if (first > second)
		swap_a(a_stack);
}

static void pull_two(t_list **a_stack, t_list **b_stack)
{
	swap_two(a_stack);
	push_b(a_stack, b_stack);
	push_b(a_stack, b_stack);
}

static void pull_uppers(t_list **a_stack, t_list **b_stack, int mid_number,
						int *lesser_numbers_left)
{
	int current_number;

	current_number = *(int *) (*a_stack)->content;
	while (current_number < mid_number)
	{
		push_b(a_stack, b_stack);
		(*lesser_numbers_left)--;
		current_number = *(int *) (*a_stack)->content;
	}
}

static void pull_lowers(t_list **a_stack, t_list **b_stack, int mid_number,
						int *lesser_numbers_left)
{
	int current_number;

	current_number = *(int *) ft_lstlast(*a_stack)->content;
	while (current_number < mid_number)
	{
		reverse_rotate_a(a_stack);
		push_b(a_stack, b_stack);
		(*lesser_numbers_left)--;
		current_number = *(int *) ft_lstlast(*a_stack)->content;
	}
}

void pull_chunk_asc(t_list **a_stack, t_list **b_stack, int chunk, int chunk_size)
{
	int mid_number;
	int lesser_numbers_left;
	int ra_count;

	if (chunk_size == 1)
		push_b(a_stack, b_stack);
	else if (chunk_size == 2)
		pull_two(a_stack, b_stack);
	else
	{
		ra_count = 0;
		mid_number = find_mid_value(*a_stack, chunk_size);
		lesser_numbers_left = chunk_size / 2;
		while (lesser_numbers_left)
		{
			pull_uppers(a_stack, b_stack, mid_number, &lesser_numbers_left);
			if (lesser_numbers_left)
			{
				rotate_a(a_stack);
				ra_count++;
			}
		}
		while (ra_count-- > 0)
			reverse_rotate_a(a_stack);
		chunk_size = get_chunk_size(*a_stack, chunk);
		pull_chunk_asc(a_stack, b_stack, chunk, chunk_size);
	}
}

void pull_last_chunk_asc(t_list **a_stack, t_list **b_stack, int chunk, int chunk_size)
{
	int mid_number;
	int lesser_numbers_left;
	bool need_to_pull_lowers;

	if (chunk_size == 1 || is_chunk_already_sorted_asc(*a_stack, chunk))
		return;
	else if (chunk_size == 2)
		swap_two(a_stack);
	else
	{
		mid_number = find_mid_value(*a_stack, chunk_size);
		lesser_numbers_left = chunk_size / 2;
		need_to_pull_lowers = true;
		while (lesser_numbers_left)
		{
			pull_uppers(a_stack, b_stack, mid_number, &lesser_numbers_left);
			if (need_to_pull_lowers)
			{
				pull_lowers(a_stack, b_stack, mid_number, &lesser_numbers_left);
				need_to_pull_lowers = false;
			}
			if (lesser_numbers_left)
				rotate_a(a_stack);
		}
		chunk_size = get_chunk_size(*a_stack, chunk);
		pull_last_chunk_asc(a_stack, b_stack, chunk, chunk_size);
	}
}
