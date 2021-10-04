#include "../includes/push_swap.h"

int get_chunk_len(t_list **stack, int chunk)
{
	int len;
	t_list *iterator;

	len = 0;
	iterator = *stack;
	while (iterator && iterator->chunk == chunk)
	{
		len++;
		iterator = iterator->next;
	}
	return len;
}

void solve_two(t_list **a_stack, t_list **b_stack)
{
	int first;
	int second;

	first = *(int *)(*b_stack)->content;
	second = *(int *)(*b_stack)->next->content;

	if (first < second)
		swap_b(b_stack);
	push_a(a_stack, b_stack);
}

void pull_chunk(t_list **a_stack, t_list **b_stack, int chunk)
{
	int chunk_len;

	while (*b_stack)
	{
		chunk_len = get_chunk_len(b_stack, chunk);
		if (chunk_len == 1)
			push_a(a_stack, b_stack);
		else if (chunk_len == 2)

	}
}