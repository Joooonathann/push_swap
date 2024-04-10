#include "push_swap.h"

void    rb(t_stack **b, int print)
{
    t_stack *tmp;
    t_stack *last;

    if (count_stack(*b) < 2)
		  return ;
    tmp = *b;
    last = *b;
    while (last->next != NULL)
        last = last->next;
    *b = (*b)->next;
    (*b)->previous = NULL;
    last->next = tmp;
    tmp->previous = last;
    tmp->next = NULL;
    if (print)
        ft_putendl_fd("rb", 1);
}