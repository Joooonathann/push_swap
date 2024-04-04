/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_pile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:41:29 by jalbiser          #+#    #+#             */
/*   Updated: 2024/04/04 13:48:09 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_pile(t_stack **stack, int pile, int print)
{
	t_stack	*first;

	if (count_stack(*stack) < 2)
		return ;
	first = *stack;
	first->next->previous = NULL;
	while ((*stack)->next != NULL)
		*stack = (*stack)->next;
	first->previous = *stack;
	first->next = NULL;
	(*stack)->next = first;
	while ((*stack)->previous != NULL)
		*stack = (*stack)->previous;
	if (pile == 1 && print)
		ft_putendl_fd("ra", 1);
	else if (pile == 2 && print)
		ft_putendl_fd("rb", 1);
}
