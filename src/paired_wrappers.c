/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paired_wrappers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdamian <bdamian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:24:08 by bdamian           #+#    #+#             */
/*   Updated: 2021/10/12 19:26:06 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_both(t_list **a_stack, t_list **b_stack)
{
	swap(a_stack);
	swap(b_stack);
}

void	rotate_both(t_list **a_stack, t_list **b_stack)
{
	rotate(a_stack);
	rotate(b_stack);
}

void	reverse_rotate_both(t_list **a_stack, t_list **b_stack)
{
	reverse_rotate(a_stack);
	reverse_rotate(b_stack);
}
