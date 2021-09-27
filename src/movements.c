#include "../includes/push_swap.h"

void push(t_list **from, t_list **to)
{
	if (ft_lst_is_empty(*from))
		return;
	ft_lstadd_front(to, *from);
	(*from) = (*from)->next;
}

void swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	*stack = second;
	(*stack)->next = first;
}

void rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = ft_lstlast(*stack);
	last->next = first;
	*stack = (*stack)->next;
	first->next = NULL;
}

void reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*previous;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next)
	{
		previous = last;
		last = last->next;
	}
	last->next = *stack;
	previous->next = NULL;
	*stack = last;
}
