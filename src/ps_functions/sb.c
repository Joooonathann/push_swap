/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:00:39 by jalbiser          #+#    #+#             */
/*   Updated: 2024/04/11 10:23:27 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack **b, int print)
{
	t_stack	*first;
	t_stack	*second;

	if (count_stack(*b) < 2)
		return ;
	first = *b;
	second = (*b)->next;
	first->next = second->next;
	first->previous = second;
	second->next = first;
	second->previous = NULL;
	if (first->next != NULL)
		first->next->previous = first;
	*b = second;
	if (print)
		ft_putendl_fd("sb", 1);
}
