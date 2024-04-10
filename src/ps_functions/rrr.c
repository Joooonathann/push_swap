#include "push_swap.h"

void    rrr(t_stack **a, t_stack **b)
{
    t_stack *last;

    if (count_stack(*a) < 2 || count_stack(*b) < 2)
		  return ;
    rra(a, 0);
    rrb(b, 0);
    ft_putendl_fd("rrr", 1);
}