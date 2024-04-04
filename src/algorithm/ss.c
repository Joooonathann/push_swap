#include "push_swap.h"

void	ss(t_stack **a, t_stack **b)
{
	swap_top(a, 1, 0);
	swap_top(b, 2, 0);
	ft_putendl_fd("ss", 1);
}