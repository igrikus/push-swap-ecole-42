#include "../includes/push_swap.h"

int get_chunk_size(t_list *stack, int chunk)
{
	int len;

	len = 0;
	while (stack && stack->chunk == chunk)
	{
		len++;
		stack = stack->next;
	}
	return len;
}

void initialize_chunks(t_list **stack)
{
	t_list *iterator;

	iterator = (*stack);
	while (iterator)
	{
		iterator->chunk = 0;
		iterator = iterator->next;
	}
}

void insert_chunk_number_len(t_list **stack, int chunk, int len)
{
	t_list *iterator;

	iterator = (*stack);
	while (iterator && len)
	{
		iterator->chunk = chunk;
		iterator = iterator->next;
		len--;
	}
}

