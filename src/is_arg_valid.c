#include "../includes/push_swap.h"

static bool is_minus_with_number(const char *str)
{
	char current_symbol;
	char next_symbol;

	current_symbol = *str;
	next_symbol = *(str + 1);
	if (current_symbol == '-' && ft_isdigit(next_symbol))
		return true;
	return false;
}

static bool is_arg_contains_only_integers(char **argv)
{
	char *temp;
	long long number;

	while (*argv)
	{
		temp = *argv;
		while (**argv)
		{
			if (ft_isdigit(**argv) || is_minus_with_number(*argv))
				(*argv)++;
			else
				return false;
		}
		*argv = temp;
		number = ft_atoll(*argv);
		if (number > INT_MAX || number < INT_MIN)
			return false;
		argv++;
	}
	return true;
}

static bool is_arg_without_duplicates(char **argv)
{
	char **current;
	char **comparing;

	current = argv;
	while (*current)
	{
		comparing = ++argv;
		while (*comparing)
		{
			if (ft_strcmp(*current, *comparing) == 0)
				return false;
			comparing++;
		}
		current = argv;
	}
	return true;
}

bool is_arg_valid(char **argv)
{
	if (is_arg_without_duplicates(argv)
		&& is_arg_contains_only_integers(argv))
		return true;
	return false;
}
