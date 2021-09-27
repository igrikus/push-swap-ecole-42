#include "../includes/push_swap.h"

bool add_element_to_stack(char *str, t_list **a_stack)
{
	int *number;
	t_list *element;

	number = malloc(sizeof(int));
	if (number == NULL)
		return false;
	*number = ft_atoi(str);
	element = ft_lstnew(number);
	if (element == NULL)
	{
		free(number);
		return false;
	}
	ft_lstadd_back(a_stack, element);
	return true;
}

bool fill_stack(t_list **a_stack, char **argv)
{
	*a_stack = 0;
	while (*argv)
	{
		if (add_element_to_stack(*argv, a_stack) == false)
		{
			ft_lstclear(a_stack, free);
			return false;
		}
		argv++;
	}
	return true;
}

bool is_already_sorted(t_list *stack)
{
	int current_number;
	int next_number;

	while (stack->next)
	{
		current_number = *(int *) stack->content;
		next_number = *(int *) stack->next->content;
		if (current_number > next_number)
			return false;
		stack = stack->next;
	}
	return true;
}

int main(int argc, char **argv)
{
	t_list *a_stack;
	t_list *temp;

	argv++;
	if (argc == 1 || !is_arg_valid(argv) || !fill_stack(&a_stack, argv))
	{
		ft_putstr_fd(ERROR_MESSAGE, STDOUT_FILENO);
		return 1;
	}
	temp = a_stack;

	int size = ft_lstsize(a_stack);
	for (int i = 0; i < size; ++i)
	{
		int number = *(int *) a_stack->content;
		printf("%d ", number);
		a_stack = a_stack->next;
	}
	ft_lstclear(&temp, free);
}
