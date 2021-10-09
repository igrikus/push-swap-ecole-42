#include "../includes/push_swap.h"

int *create_array_from_list(t_list *stack, int len)
{
	int counter;
	int *array;

	array = malloc(sizeof(int) * len);
	if (array == NULL)
		return NULL;
	counter = 0;
	while (counter < len)
	{
		array[counter] = *(int *) stack->content;
		stack = stack->next;
		counter++;
	}
	return (array);
}

void sort_array(int *array, int len)
{
	int i;
	int j;
	int temp;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int		find_mid_value(t_list *stack, int len)
{
	int *array;
	int	mid_value;

	array = create_array_from_list(stack, len);
	sort_array(array, len);
	mid_value = array[len / 2];
	free(array);
	return (mid_value);
}
