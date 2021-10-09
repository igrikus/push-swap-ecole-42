#include "../includes/push_swap.h"

static int	pull_uppers(t_list **a_stack, t_list **b_stack, int mid_num,
						  int *bigger_left)
{
	int	pulled_count;
	int	current_number;

	pulled_count = 0;
	current_number = *(int *)(*b_stack)->content;
	while (current_number > mid_num)
	{
		push_a(a_stack, b_stack);
		pulled_count++;
		(*bigger_left)--;
		current_number = *(int *)(*b_stack)->content;
	}
	return (pulled_count);
}

static int	pull_lowers(t_list **a_stack, t_list **b_stack, int mid_num,
						  int *bigger_left)
{
	int	pulled_count;
	int	current_number;

	pulled_count = 0;
	current_number = *(int *) ft_lstlast(*b_stack)->content;
	while (current_number > mid_num)
	{
		reverse_rotate_b(b_stack);
		push_a(a_stack, b_stack);
		pulled_count++;
		(*bigger_left)--;
		current_number = *(int *) ft_lstlast(*b_stack)->content;
	}
	return (pulled_count);
}

static int	pull_chunk(t_list **a_stack, t_list **b_stack, int chunk_size)
{
	int	mid_num;
	int	pulled_len;
	int	bigger_left;
	int	rb_count;

	rb_count = 0;
	pulled_len = 0;
	mid_num = find_mid_value(*b_stack, chunk_size);
	if (chunk_size % 2 == 1)
		bigger_left = chunk_size / 2;
	else
		bigger_left = (chunk_size / 2) - 1;
	while (bigger_left)
	{
		pulled_len += pull_uppers(a_stack, b_stack, mid_num, &bigger_left);
		if (bigger_left)
		{
			rotate_b(b_stack);
			rb_count++;
		}
	}
	while (rb_count-- > 0)
		reverse_rotate_b(b_stack);
	return (pulled_len);
}

static int	pull_last_chunk(t_list **a_stack, t_list **b_stack, int chunk_size)
{
	int		mid_num;
	int		pulled_len;
	int		bigger_left;
	bool	need_to_pull_lowers;

	pulled_len = 0;
	mid_num = find_mid_value(*b_stack, chunk_size);
	if (chunk_size % 2 == 1)
		bigger_left = chunk_size / 2;
	else
		bigger_left = (chunk_size / 2) - 1;
	need_to_pull_lowers = true;
	while (bigger_left)
	{
		pulled_len += pull_uppers(a_stack, b_stack, mid_num, &bigger_left);
		if (need_to_pull_lowers)
		{
			pulled_len += pull_lowers(a_stack, b_stack, mid_num, &bigger_left);
			need_to_pull_lowers = false;
		}
		if (bigger_left)
			rotate_b(b_stack);
	}
	return (pulled_len);
}

void	pull_chunk_to_a(t_list **a_stack, t_list **b_stack, int *chunk,
						int pulled_chunk)
{
	int	pulled_len;
	int	chunk_size;

	chunk_size = get_chunk_size(*b_stack, *chunk);
	if (chunk_size <= 2)
	{
		pulled_len = chunk_size;
		(*chunk)--;
		if (chunk_size == 1)
			push_a(a_stack, b_stack);
		else
			pull_two_to_a(a_stack, b_stack);
	}
	else if (*chunk != 0)
		pulled_len = pull_chunk(a_stack, b_stack, chunk_size);
	else
		pulled_len = pull_last_chunk(a_stack, b_stack, chunk_size);
	insert_chunk_number_len(a_stack, pulled_chunk, pulled_len);
}
