#include "push_swap.h"

void    swap_top(t_stack **stack, int pile)
{
    t_stack *a;
	t_stack	*b;

	a = *stack;
	b = (*stack)->next;
	a->next = b->next;
	a->previous = b;
	b->next = a;
	b->previous = NULL;
	*stack = b;
	if (pile == 1)
		ft_putendl_fd("sa", 1);
	else if (pile == 2)
		ft_putendl_fd("sb", 1);
}