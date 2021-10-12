/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_wrappers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdamian <bdamian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:24:15 by bdamian           #+#    #+#             */
/*   Updated: 2021/10/12 19:26:06 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_a(t_list **a_stack, t_list **b_stack)
{
	push(b_stack, a_stack);
	ft_putendl_fd(PUSH_A, STDOUT_FILENO);
}

void	push_b(t_list **a_stack, t_list **b_stack)
{
	push(a_stack, b_stack);
	ft_putendl_fd(PUSH_B, STDOUT_FILENO);
}

void	swap_a(t_list **a_stack)
{
	swap(a_stack);
	ft_putendl_fd(SWAP_A, STDOUT_FILENO);
}

void	swap_b(t_list **b_stack)
{
	swap(b_stack);
	ft_putendl_fd(SWAP_B, STDOUT_FILENO);
}
