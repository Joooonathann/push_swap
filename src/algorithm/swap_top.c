/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_top.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:42:16 by jalbiser          #+#    #+#             */
/*   Updated: 2024/04/04 13:41:24 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top(t_stack **stack, int pile, int print)
{
	t_stack *a;
	t_stack	*b;

	if (count_stack(*stack) < 2)
		return ;
	a = *stack;
	b = (*stack)->next;
	a->next = b->next;
	a->previous = b;
	b->next = a;
	b->previous = NULL;
	*stack = b;
	if (pile == 1 && print)
		ft_putendl_fd("sa", 1);
	else if (pile == 2 && print)
		ft_putendl_fd("sb", 1);
}
