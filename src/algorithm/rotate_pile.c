/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_pile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:41:29 by jalbiser          #+#    #+#             */
/*   Updated: 2024/04/10 15:22:20 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ps_lstlast(t_stack *stack)
{
	t_stack	*temp;

	temp = NULL;
	if (stack != NULL)
	{
		temp = stack;
		while (temp-> next)
		{
			temp = temp->next;
		}
	}
	return (temp);
}

void	rotate_pile(t_stack **stack, int pile, int print)
{
	t_stack	*first;
	t_stack	*last;
	
	if (count_stack(*stack) < 2)
		return ;
	first = *stack;
	last = ps_lstlast(*stack);
	*stack = (*stack)->next;
	(*stack)->previous = NULL;
	first->next = NULL;
	first->previous = last;
	last->next = first;
	while ((*stack)->previous != NULL)
		*stack = (*stack)->previous;
	if (pile == 1 && print)
		ft_putendl_fd("ra", 1);
	else if (pile == 2 && print)
		ft_putendl_fd("rb", 1);
}
