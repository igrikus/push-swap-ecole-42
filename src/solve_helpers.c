#include "../includes/push_swap.h"

int find_min_number_position(t_list *stack)
{
	int counter;
	int position;
	int min_number;
	int current_number;

	min_number = *(int *)stack->content;
	counter = 0;
	position = counter;
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

void rotate_min_to_top(t_list **stack, int stack_size)
{
	int counter;
	int half_size;
	int difference;
	int min_num_pos;

	half_size = stack_size / 2;
	min_num_pos = find_min_number_position(*stack);
	counter = 0;
	if (min_num_pos <= half_size)
		while (counter < min_num_pos)
		{
			rotate_a(stack);
			counter++;
		}
	else
	{
		difference = stack_size - min_num_pos;
		while (counter < difference)
		{
			reverse_rotate_a(stack);
			counter++;
		}
	}
}
