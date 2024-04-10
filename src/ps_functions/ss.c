#include "push_swap.h"

void    ss(t_stack **a, t_stack **b)
{
    t_stack *tmp;

    if (!*a || !*b)
        return ;
    if (count_stack(*a) < 2 || count_stack(*b) < 2)
        return ;
    sa(a, 0);
    sb(b, 0);
    ft_putendl_fd("ss", 1);
}