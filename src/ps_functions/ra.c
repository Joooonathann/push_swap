#include "push_swap.h"

void    ra(t_stack **a, int print)
{
    t_stack *tmp;
    t_stack *last;

    if (count_stack(*a) < 2)
		  return ;
    tmp = *a;
    last = *a;
    while (last->next != NULL)
        last = last->next;
    *a = (*a)->next;
    (*a)->previous = NULL;
    last->next = tmp;
    tmp->previous = last;
    tmp->next = NULL;
    if (print)
        ft_putendl_fd("ra", 1);
}