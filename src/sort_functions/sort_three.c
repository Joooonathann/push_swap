/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:05:31 by jalbiser          #+#    #+#             */
/*   Updated: 2024/04/11 10:18:44 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	int	biggest;

	biggest = find_biggest(*stack);
	if ((*stack)->number == biggest)
		ra(stack, 1);
	else if ((*stack)->next->number == biggest)
		rra(stack, 1);
	if ((*stack)->number > (*stack)->next->number)
		sa(stack, 1);
}
