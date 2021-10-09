#include "../includes/push_swap.h"

void	push(t_list **from, t_list **to)
{
	t_list	*temp;
	t_list	*temp_from;
	t_list	*temp_to;

	temp_from = *from;
	if (!temp_from)
		return ;
	temp_to = *to;
	temp = temp_from;
	temp_from = temp_from->next;
	*from = temp_from;
	if (!temp_to)
	{
		temp_to = temp;
		temp_to->next = NULL;
		*to = temp_to;
	}
	else
	{
		temp->next = temp_to;
		*to = temp;
	}
}

void	swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;
	int		*temp_number;

	if (!(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	temp_number = (int *) first->content;
	first->content = second->content;
	second->content = temp_number;
}

void	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;
	t_list	*temp_stack;

	temp_stack = *stack;
	if (!temp_stack || !temp_stack->next)
		return ;
	first = temp_stack;
	temp_stack = temp_stack->next;
	last = ft_lstlast(temp_stack);
	last->next = first;
	first->next = NULL;
	*stack = temp_stack;
}

void	reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*previous;
	t_list	*temp_stack;

	temp_stack = *stack;
	if (!temp_stack || !temp_stack->next)
		return ;
	last = temp_stack;
	while (last->next)
	{
		previous = last;
		last = last->next;
	}
	last->next = temp_stack;
	previous->next = NULL;
	*stack = last;
}
