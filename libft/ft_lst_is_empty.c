#include "libft.h"

int ft_lst_is_empty(t_list *lst)
{
	int size;

	size = ft_lstsize(lst);
	if (size == 0)
		return 1;
	return 0;
}
