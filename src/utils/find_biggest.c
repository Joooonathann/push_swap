/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_biggest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:04:32 by jalbiser          #+#    #+#             */
/*   Updated: 2024/04/11 10:21:33 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_biggest(t_stack *stack)
{
	int	i;

	if (!stack)
		return (0);
	i = -2147483648;
	while (stack)
	{
		if (stack->number > i)
			i = stack->number;
		stack = stack->next;
	}
	return (i);
}
