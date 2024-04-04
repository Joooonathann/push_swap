/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse_pile.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:41:29 by jalbiser          #+#    #+#             */
/*   Updated: 2024/04/04 13:51:53 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_reverse_pile(t_stack **stack, int pile, int print)
{
	t_stack	*first;
	t_stack	*last;
	
	if (count_stack(*stack) < 2)
		return ;
	first = *stack;
	while ((*stack)->next != NULL)
		*stack = (*stack)->next;
	last = *stack;
	*stack= first;
	first->previous = last;
	last->next = first;
	last->previous = NULL;
	if (pile == 1 && print)
		ft_putendl_fd("rra", 1);
	else if (pile == 2 && print)
		ft_putendl_fd("rrb", 1);
}
