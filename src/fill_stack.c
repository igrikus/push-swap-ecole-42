#include "../includes/push_swap.h"

static bool	add_element_to_stack(char *str, t_list **a_stack)
{
	int		*number;
	t_list	*element;

	number = malloc(sizeof(int));
	if (number == NULL)
		return (false);
	*number = ft_atoi(str);
	element = ft_lstnew(number);
	if (element == NULL)
	{
		free(number);
		return (false);
	}
	ft_lstadd_back(a_stack, element);
	return (true);
}

bool	fill_stack(t_list **a_stack, char **argv)
{
	while (*argv)
	{
		if (add_element_to_stack(*argv, a_stack) == false)
		{
			ft_lstclear(a_stack, free);
			return (false);
		}
		argv++;
	}
	return (true);
}
