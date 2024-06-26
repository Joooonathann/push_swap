/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:00:27 by jalbiser          #+#    #+#             */
/*   Updated: 2024/04/11 10:23:23 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a, int print)
{
	t_stack	*first;
	t_stack	*second;

	if (count_stack(*a) < 2)
		return ;
	first = *a;
	second = (*a)->next;
	first->next = second->next;
	first->previous = second;
	second->next = first;
	second->previous = NULL;
	if (first->next != NULL)
		first->next->previous = first;
	*a = second;
	if (print)
		ft_putendl_fd("sa", 1);
}
