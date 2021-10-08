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

static int pull_uppers(t_list **a_stack, t_list **b_stack, int mid_number, int *bigger_numbers_left)
{
	int pulled_count;
	int current_number;

	pulled_count = 0;
	current_number = *(int *) (*b_stack)->content;
	while (current_number > mid_number)
	{
		push_a(a_stack, b_stack);
		pulled_count++;
		(*bigger_numbers_left)--;
		current_number = *(int *) (*b_stack)->content;
	}
	return pulled_count;
}

static int pull_lowers(t_list **a_stack, t_list **b_stack, int mid_number, int *bigger_numbers_left)
{
	int pulled_count;
	int current_number;

	pulled_count = 0;
	current_number = *(int *) ft_lstlast(*b_stack)->content;
	while (current_number > mid_number)
	{
		reverse_rotate_b(b_stack);
		push_a(a_stack, b_stack);
		pulled_count++;
		(*bigger_numbers_left)--;
		current_number = *(int *) ft_lstlast(*b_stack)->content;
	}
	return pulled_count;
}

static int pull_chunk(t_list **a_stack, t_list **b_stack, int chunk_size)
{
	int mid_number;
	int pulled_len;
	int bigger_numbers_left;
	int rb_count;

	if (chunk_size == 1)
	{
		push_a(a_stack, b_stack);
		pulled_len = 1;
	}
	else if (chunk_size == 2)
	{
		pull_two(a_stack, b_stack);
		pulled_len = 2;
	}
	else
	{
		rb_count = 0;
		pulled_len = 0;
		mid_number = find_mid_value(*b_stack, chunk_size);
		bigger_numbers_left = chunk_size / 2;
		while (bigger_numbers_left)
		{
			pulled_len += pull_uppers(a_stack, b_stack, mid_number, &bigger_numbers_left);
			if (bigger_numbers_left)
			{
				rotate_b(b_stack);
				rb_count++;
			}
		}
		while (rb_count-- > 0)
			reverse_rotate_b(b_stack);
	}
	return pulled_len;
}

static int pull_last_chunk(t_list **a_stack, t_list **b_stack, int chunk_size)
{
	int mid_number;
	int pulled_len;
	int bigger_numbers_left;
	bool need_to_pull_lowers;

	if (chunk_size == 1)
	{
		push_a(a_stack, b_stack);
		pulled_len = 1;
	}
	else if (chunk_size == 2)
	{
		pull_two(a_stack, b_stack);
		pulled_len = 2;
	}
	else
	{
		pulled_len = 0;
		mid_number = find_mid_value(*b_stack, chunk_size);
		bigger_numbers_left = chunk_size / 2;
		need_to_pull_lowers = true;
		while (bigger_numbers_left)
		{
			pulled_len += pull_uppers(a_stack, b_stack, mid_number, &bigger_numbers_left);
			if (need_to_pull_lowers)
			{
				pulled_len += pull_lowers(a_stack, b_stack, mid_number, &bigger_numbers_left);
				need_to_pull_lowers = false;
			}
			if (bigger_numbers_left)
				rotate_b(b_stack);
		}
	}
	return pulled_len;
}

void pull_chunk_to_a(t_list **a_stack, t_list **b_stack, int *chunk, int pulled_chunk)
{
    int pulled_len;
	int chunk_size;

    chunk_size = get_chunk_size(*b_stack, *chunk);
    if (*chunk != 0)
        pulled_len = pull_chunk(a_stack, b_stack, chunk_size);
    else
		pulled_len = pull_last_chunk(a_stack, b_stack, chunk_size);
	if (chunk_size <= 2)
		(*chunk)--;
	insert_chunk_number_len(a_stack, pulled_chunk, pulled_len);
}
