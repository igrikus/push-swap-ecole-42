#include "../includes/push_swap.h"

static int	push_uppers(t_list **a_stack, t_list **b_stack, int mid_num,
						  int *bigger_left)
{
	int	pushed_count;
	int	current_number;

	pushed_count = 0;
	current_number = *(int *)(*b_stack)->content;
	while (current_number > mid_num)
	{
		push_a(a_stack, b_stack);
		pushed_count++;
		(*bigger_left)--;
		current_number = *(int *)(*b_stack)->content;
	}
	return (pushed_count);
}

static int	push_lowers(t_list **a_stack, t_list **b_stack, int mid_num,
						  int *bigger_left)
{
	int	pushed_count;
	int	current_number;

	pushed_count = 0;
	current_number = *(int *) ft_lstlast(*b_stack)->content;
	while (current_number > mid_num)
	{
		reverse_rotate_b(b_stack);
		push_a(a_stack, b_stack);
		pushed_count++;
		(*bigger_left)--;
		current_number = *(int *) ft_lstlast(*b_stack)->content;
	}
	return (pushed_count);
}

static int	push_chunk(t_list **a_stack, t_list **b_stack, int chunk_size)
{
	int	mid_num;
	int	pushed_len;
	int	bigger_left;
	int	rb_count;

	rb_count = 0;
	pushed_len = 0;
	mid_num = find_mid_value(*b_stack, chunk_size);
	if (chunk_size % 2 == 1)
		bigger_left = chunk_size / 2;
	else
		bigger_left = (chunk_size / 2) - 1;
	while (bigger_left)
	{
		pushed_len += push_uppers(a_stack, b_stack, mid_num, &bigger_left);
		if (bigger_left)
		{
			rotate_b(b_stack);
			rb_count++;
		}
	}
	while (rb_count-- > 0)
		reverse_rotate_b(b_stack);
	return (pushed_len);
}

static int	push_last_chunk(t_list **a_stack, t_list **b_stack, int chunk_size)
{
	int		mid_num;
	int		pushed_len;
	int		bigger_left;
	bool	need_to_push_lowers;

	pushed_len = 0;
	mid_num = find_mid_value(*b_stack, chunk_size);
	if (chunk_size % 2 == 1)
		bigger_left = chunk_size / 2;
	else
		bigger_left = (chunk_size / 2) - 1;
	need_to_push_lowers = true;
	while (bigger_left)
	{
		pushed_len += push_uppers(a_stack, b_stack, mid_num, &bigger_left);
		if (need_to_push_lowers)
		{
			pushed_len += push_lowers(a_stack, b_stack, mid_num, &bigger_left);
			need_to_push_lowers = false;
		}
		if (bigger_left)
			rotate_b(b_stack);
	}
	return (pushed_len);
}

void	push_chunk_to_a(t_list **a_stack, t_list **b_stack, int *chunk,
						int pushed_chunk)
{
	int	pushed_len;
	int	chunk_size;

	chunk_size = get_chunk_size(*b_stack, *chunk);
	if (chunk_size <= 2)
	{
		pushed_len = chunk_size;
		(*chunk)--;
		if (chunk_size == 1)
			push_a(a_stack, b_stack);
		else
			pull_two_to_a(a_stack, b_stack);
	}
	else if (*chunk != 0)
		pushed_len = push_chunk(a_stack, b_stack, chunk_size);
	else
		pushed_len = push_last_chunk(a_stack, b_stack, chunk_size);
	insert_chunk_number(a_stack, pushed_chunk, pushed_len);
}
