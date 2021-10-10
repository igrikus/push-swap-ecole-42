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
