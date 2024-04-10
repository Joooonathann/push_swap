#include "push_swap.h"

void	ss(t_stack **a, t_stack **b)
{
	if ((count_stack(*a) < 2) || (count_stack(*b) < 2))
		return ;
	swap_top(a, 1, 0);
	swap_top(b, 2, 0);
	ft_putendl_fd("ss", 1);
}