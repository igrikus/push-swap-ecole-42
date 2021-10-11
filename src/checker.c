#include "../includes/push_swap.h"
#include "../includes/wrappers.h"

int	error_situation(t_list **a_stack, t_list **b_stack, char *line)
{
	ft_putendl_fd(ERROR_MESSAGE, STDOUT_FILENO);
	if (*a_stack)
		ft_lstclear(a_stack, free);
	if (*b_stack)
		ft_lstclear(b_stack, free);
	if (line)
		free(line);
	exit(1);
}

void	perform_command(t_list **a_stack, t_list **b_stack, char *line)
{
	if (ft_strcmp(line, PUSH_A) == 0)
		push(b_stack, a_stack);
	else if (ft_strcmp(line, PUSH_B) == 0)
		push(a_stack, b_stack);
	else if (ft_strcmp(line, SWAP_A) == 0)
		swap(a_stack);
	else if (ft_strcmp(line, SWAP_B) == 0)
		swap(b_stack);
	else if (ft_strcmp(line, SWAP_BOTH) == 0)
		swap_both(a_stack, b_stack);
	else if (ft_strcmp(line, ROTATE_A) == 0)
		rotate(a_stack);
	else if (ft_strcmp(line, ROTATE_B) == 0)
		rotate(b_stack);
	else if (ft_strcmp(line, ROTATE_BOTH) == 0)
		rotate_both(a_stack, b_stack);
	else if (ft_strcmp(line, REVERSE_ROTATE_A) == 0)
		reverse_rotate(a_stack);
	else if (ft_strcmp(line, REVERSE_ROTATE_B) == 0)
		reverse_rotate(b_stack);
	else if (ft_strcmp(line, REVERSE_ROTATE_BOTH) == 0)
		reverse_rotate_both(a_stack, b_stack);
	else
		error_situation(a_stack, b_stack, line);
}

void	check_result(t_list **a_stack, t_list **b_stack)
{
	if (is_stack_already_sorted(*a_stack) && (*b_stack) == NULL)
		ft_putendl_fd(OK_MESSAGE, STDOUT_FILENO);
	else
		ft_putendl_fd(KO_MESSAGE, STDOUT_FILENO);
	if (*a_stack)
		ft_lstclear(a_stack, free);
	if (*b_stack)
		ft_lstclear(b_stack, free);
}

int	main(int argc, char **argv)
{
	char	*line;
	t_list	*a_stack;
	t_list	*b_stack;

	if (argc == 1)
	{
		ft_putendl_fd(PROMPT_MESSAGE, STDOUT_FILENO);
		return (0);
	}
	argv++;
	line = NULL;
	a_stack = NULL;
	b_stack = NULL;
	if (argc == 2)
		argv = ft_split(*argv, ' ');
	if (!argv || !*argv || !is_arg_valid(argv) || !fill_stack(&a_stack, argv))
		error_situation(&a_stack, &b_stack, line);
	while (get_next_line(STDIN_FILENO, &line))
	{
		perform_command(&a_stack, &b_stack, line);
		free(line);
	}
	check_result(&a_stack, &b_stack);
}
