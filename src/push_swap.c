#include "../includes/push_swap.h"

int main(int argc, char **argv)
{
    argv++;

    if (argc == 1 || is_arg_valid(argv) != true)
        ft_putstr_fd(ERROR_MESSAGE, STDOUT_FILENO);
}
