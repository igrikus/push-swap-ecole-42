/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdamian <bdamian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:23:59 by bdamian           #+#    #+#             */
/*   Updated: 2021/10/12 19:26:06 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_chunk_size(t_list *stack, int chunk)
{
	int	len;

	len = 0;
	while (stack && stack->chunk == chunk)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

void	initialize_chunks(t_list **stack)
{
	t_list	*iterator;

	iterator = (*stack);
	while (iterator)
	{
		iterator->chunk = 0;
		iterator = iterator->next;
	}
}

void	insert_chunk_number(t_list **stack, int chunk, int len)
{
	t_list	*iterator;

	iterator = (*stack);
	while (iterator && len)
	{
		iterator->chunk = chunk;
		iterator = iterator->next;
		len--;
	}
}

void	push_two_to_b(t_list **a_stack, t_list **b_stack)
{
	solve_two(a_stack);
	push_b(a_stack, b_stack);
	push_b(a_stack, b_stack);
}

void	pull_two_to_a(t_list **a_stack, t_list **b_stack)
{
	int	first;
	int	second;

	first = *(int *)(*b_stack)->content;
	second = *(int *)(*b_stack)->next->content;
	if (first < second)
		swap_b(b_stack);
	push_a(a_stack, b_stack);
	push_a(a_stack, b_stack);
}
