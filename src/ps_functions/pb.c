#include "push_swap.h"

void    pb(t_stack **a, t_stack **b, int print)
{
    t_stack *tmp;

    if (!*a)
        return ;
    tmp = *a;
    *a = (*a)->next;
    if (*a)
        (*a)->previous = NULL;
    if (!*b)
    {
        tmp->next = NULL;
        *b = tmp;
    }
    else
    {
        tmp->next = *b;
        (*b)->previous = tmp;
        *b = tmp;
    }
    if (print)
        ft_putendl_fd("pb", 1);
}