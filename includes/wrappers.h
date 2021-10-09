#ifndef WRAPPERS_H
# define WRAPPERS_H

# include "../libft/libft.h"

# define SWAP_A "sa"
# define SWAP_B "sb"
# define PUSH_A "pa"
# define PUSH_B "pb"
# define ROTATE_A "ra"
# define ROTATE_B "rb"
# define REVERSE_ROTATE_A "rra"
# define REVERSE_ROTATE_B "rrb"

void	push(t_list **from, t_list **to);
void	swap(t_list **stack);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);
#endif
