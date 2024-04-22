/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:30:54 by jalbiser          #+#    #+#             */
/*   Updated: 2024/04/22 11:36:38 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_max(t_stack *stack)
{
	t_stack	*max;
	long	best_match_index;

	if (!stack)
		return (NULL);
	max = NULL;
	best_match_index = LONG_MIN;
	while (stack)
	{
		if (stack->number > best_match_index)
		{
			best_match_index = stack->number;
			max = stack;
		}
		stack = stack->next;
	}
	return (max);
}

t_stack	*find_min(t_stack *stack)
{
	t_stack	*min;
	long	best_match_index;

	if (!stack)
		return (NULL);
	min = NULL;
	best_match_index = LONG_MAX;
	while (stack)
	{
		if (stack->number < best_match_index)
		{
			best_match_index = stack->number;
			min = stack;
		}
		stack = stack->next;
	}
	return (min);
}
