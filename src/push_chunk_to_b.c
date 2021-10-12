/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunk_to_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdamian <bdamian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:24:13 by bdamian           #+#    #+#             */
/*   Updated: 2021/10/12 19:26:16 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	push_uppers(t_list **a_stack, t_list **b_stack, int mid_num,
						int *lesser_left)
{
	int	pulled_count;
	int	current_number;

	pulled_count = 0;
	current_number = *(int *)(*a_stack)->content;
	while (current_number < mid_num)
	{
		push_b(a_stack, b_stack);
		pulled_count++;
		(*lesser_left)--;
		current_number = *(int *)(*a_stack)->content;
	}
	return (pulled_count);
}

static int	push_lowers(t_list **a_stack, t_list **b_stack, int mid_num,
						int *lesser_left)
{
	int	pulled_count;
	int	current_number;

	pulled_count = 0;
	current_number = *(int *) ft_lstlast(*a_stack)->content;
	while (current_number < mid_num)
	{
		reverse_rotate_a(a_stack);
		push_b(a_stack, b_stack);
		pulled_count++;
		(*lesser_left)--;
		current_number = *(int *) ft_lstlast(*a_stack)->content;
	}
	return (pulled_count);
}

static int	push_chunk(t_list **a_stack, t_list **b_stack, int chunk_size)
{
	int	mid_num;
	int	pushed_len;
	int	lesser_left;
	int	ra_count;

	pushed_len = 0;
	ra_count = 0;
	mid_num = find_mid_value(*a_stack, chunk_size);
	lesser_left = chunk_size / 2;
	while (lesser_left)
	{
		pushed_len += push_uppers(a_stack, b_stack, mid_num, &lesser_left);
		if (lesser_left)
		{
			rotate_a(a_stack);
			ra_count++;
		}
	}
	while (ra_count-- > 0)
		reverse_rotate_a(a_stack);
	return (pushed_len);
}

static int	push_last_chunk(t_list **a_stack, t_list **b_stack, int chunk_size)
{
	int		mid_num;
	int		pushed_len;
	int		lesser_left;
	bool	need_to_push_lowers;

	pushed_len = 0;
	mid_num = find_mid_value(*a_stack, chunk_size);
	lesser_left = chunk_size / 2;
	need_to_push_lowers = true;
	while (lesser_left)
	{
		pushed_len += push_uppers(a_stack, b_stack, mid_num, &lesser_left);
		if (need_to_push_lowers)
		{
			pushed_len += push_lowers(a_stack, b_stack, mid_num, &lesser_left);
			need_to_push_lowers = false;
		}
		if (lesser_left)
			rotate_a(a_stack);
	}
	return (pushed_len);
}

void	push_chunk_to_b(t_list **a_stack, t_list **b_stack, int *chunk,
						int pushed_chunk)
{
	int	pushed_len;
	int	chunk_size;

	chunk_size = get_chunk_size(*a_stack, *chunk);
	if (chunk_size <= 2)
	{
		pushed_len = chunk_size;
		(*chunk)--;
		if (*chunk == 0 && chunk_size == 2)
			solve_two(a_stack);
		else if (*chunk != 0 && chunk_size == 2)
			push_two_to_b(a_stack, b_stack);
		else
			push_b(a_stack, b_stack);
	}
	else if (*chunk != 0)
		pushed_len = push_chunk(a_stack, b_stack, chunk_size);
	else
		pushed_len = push_last_chunk(a_stack, b_stack, chunk_size);
	insert_chunk_number(b_stack, pushed_chunk, pushed_len);
}
