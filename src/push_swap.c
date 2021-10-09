#include "../includes/push_swap.h"

static void	free_resources(t_list **a_stack, int argc, char **strings)
{
	char	**temp;

	if (argc == 2)
	{
		temp = strings;
		while (*strings)
		{
			free(*strings);
			strings++;
		}
		free(temp);
	}
	ft_lstclear(a_stack, free);
}

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

static bool	fill_stack(t_list **a_stack, char **argv)
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

int	main(int argc, char **argv)
{
	t_list	*a_stack;
	t_list	*b_stack;

	if (argc == 1)
	{
		ft_putendl_fd(PROMPT_MESSAGE, STDOUT_FILENO);
		return (0);
	}
	argv++;
	a_stack = NULL;
	b_stack = NULL;
	if (argc == 2)
		argv = ft_split(*argv, ' ');
	if (!argv || !*argv || !is_arg_valid(argv) || !fill_stack(&a_stack, argv))
	{
		ft_putendl_fd(ERROR_MESSAGE, STDOUT_FILENO);
		return (1);
	}
	solve(&a_stack, &b_stack);
	free_resources(&a_stack, argc, argv);
}
