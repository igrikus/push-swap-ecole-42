/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_wrappers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdamian <bdamian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:24:20 by bdamian           #+#    #+#             */
/*   Updated: 2021/10/12 19:26:06 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_a(t_list **a_stack)
{
	rotate(a_stack);
	ft_putendl_fd(ROTATE_A, STDOUT_FILENO);
}

void	rotate_b(t_list **b_stack)
{
	rotate(b_stack);
	ft_putendl_fd(ROTATE_B, STDOUT_FILENO);
}

void	reverse_rotate_a(t_list **a_stack)
{
	reverse_rotate(a_stack);
	ft_putendl_fd(REVERSE_ROTATE_A, STDOUT_FILENO);
}

void	reverse_rotate_b(t_list **b_stack)
{
	reverse_rotate(b_stack);
	ft_putendl_fd(REVERSE_ROTATE_B, STDOUT_FILENO);
}
