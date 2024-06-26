/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:00:05 by jalbiser          #+#    #+#             */
/*   Updated: 2024/04/11 10:23:09 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_stack **b, int print)
{
	t_stack	*last;

	if (count_stack(*b) < 2)
		return ;
	last = *b;
	while (last->next != NULL)
		last = last->next;
	last->previous->next = NULL;
	last->previous = NULL;
	last->next = *b;
	(*b)->previous = last;
	*b = last;
	if (print)
		ft_putendl_fd("rrb", 1);
}
