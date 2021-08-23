#include "../includes/push_swap.h"

t_list* add_args_to_list(int argc, char **argv)
{
    int arg_counter;
    int char_counter;
    t_list *number;
    t_list *a_stack;

    a_stack = 0;
    arg_counter = 1;
    while (arg_counter < argc)
    {
        char_counter = 0;
        while (argv[arg_counter][char_counter])
        {
            if (!ft_isdigit(argv[arg_counter][char_counter]))
                return 0;
            else if (argv[arg_counter][char_counter + 1] == 0)
            {
                number = ft_lstnew(argv[arg_counter]);
                ft_lstadd_back(&a_stack, number);
            }
            char_counter++;
        }
        arg_counter++;
    }
    return a_stack;
}

int main(int argc, char **argv)
{
    t_list *a_stack;

    if (argc == 1)
    {
        ft_putstr_fd(ERROR_MESSAGE, 1);
        exit(0);
    }
    a_stack = add_args_to_list(argc, argv);
    if (a_stack == 0)
    {
        ft_putstr_fd(ERROR_MESSAGE, 1);
        ft_lstclear(&a_stack, free);
        exit(0);
    }
    int size = ft_lstsize(a_stack);
    for (int i = 0; i < size; ++i) {
        printf("%s", (char *)a_stack->content);
        a_stack = a_stack->next;
    }
}
