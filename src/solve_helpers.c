#include "../includes/push_swap.h"

int find_min_number_position(t_list *stack)
{
	int counter;
	int position;
	int min_number;
	int current_number;

	min_number = *(int *)stack->content;
	counter = 0;
	while (stack)
	{
		current_number = *(int *)stack->content;
		if(current_number < min_number) {
			min_number = current_number;
			position = counter;
		}
		stack = stack->next;
		counter++;
	}
	return position;
}

void rotate_min_to_top(t_list **stack, int pos, int stack_size, int half_size)
{
	int counter;
	int difference;

	counter = 0;
	if (pos <= half_size)
		while (counter < pos)
		{
			rotate_a(stack);
			counter++;
		}
	else
	{
		difference = stack_size - pos;
		while (counter < difference)
		{
			reverse_rotate_a(stack);
			counter++;
		}
	}
}
