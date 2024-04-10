#include "push_swap.h"

void    rra(t_stack **a, int print)
{
    t_stack *last;

    if (count_stack(*a) < 2)
		  return ;
    last = *a;
    while (last->next != NULL)
      last = last->next;
    last->previous->next = NULL;
    last->previous = NULL;
    last->next = *a;
    (*a)->previous = last;
    *a = last;
    if (print)
        ft_putendl_fd("rra", 1);
}