/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_to_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:30:18 by jalbiser          #+#    #+#             */
/*   Updated: 2024/04/22 11:36:31 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prep_to_push(t_stack **stack, t_stack *to_rotate, char stack_name)
{
	while (*stack != to_rotate)
	{
		if (stack_name == 'a')
		{
			if (to_rotate->above_median)
				ra(stack, 1);
			else
				rra(stack, 1);
		}
		else if (stack_name == 'b')
		{
			if (to_rotate->above_median)
				rb(stack, 1);
			else
				rrb(stack, 1);
		}
	}
}
