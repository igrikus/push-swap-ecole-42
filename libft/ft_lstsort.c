/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdamian <bdamian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:22:39 by bdamian           #+#    #+#             */
/*   Updated: 2021/10/12 19:26:06 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsort(t_list **begin_list, int (*cmp)())
{
	void	*temp;
	t_list	*current;
	t_list	*comparing;

	current = (*begin_list);
	while (current)
	{
		comparing = current->next;
		while (comparing)
		{
			if ((*cmp)(current->content, comparing->content) > 0)
			{
				temp = current->content;
				current->content = comparing->content;
				comparing->content = temp;
			}
			comparing = comparing->next;
		}
		current = current->next;
	}
}
