/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:41:36 by jalbiser          #+#    #+#             */
/*   Updated: 2024/04/08 14:25:15 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack(t_stack **a, t_stack **b, int pile, int print)
{
	t_stack	*tmp;

	if (*b == NULL)
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
		tmp->next = *a;
		(*a)->previous = tmp;
		*a = tmp;
	}
	if (pile == 1 && print)
		ft_putendl_fd("pa", 1);
	else if (pile == 2 && print)
		ft_putendl_fd("pb", 1);
}
