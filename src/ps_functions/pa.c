/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:59:08 by jalbiser          #+#    #+#             */
/*   Updated: 2024/04/11 10:22:30 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b, int print)
{
	t_stack	*tmp;

	if (!*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->previous = NULL;
	if (!*a)
	{
		*a = tmp;
		tmp->next = NULL;
	}
	else
	{
		(*a)->previous = tmp;
		tmp->next = *a;
		*a = tmp;
	}
	if (print)
		ft_putendl_fd("pa", 1);
}
