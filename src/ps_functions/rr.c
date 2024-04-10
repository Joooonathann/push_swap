#include "push_swap.h"

void    rr(t_stack **a, t_stack **b)
{
    if (count_stack(*a) < 2 || count_stack(*b) < 2)
		  return ;
    ra(a, 0);
    rb(b, 0);
    ft_putendl_fd("rr", 1);
}