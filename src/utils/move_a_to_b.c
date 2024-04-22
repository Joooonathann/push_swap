/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:32:11 by jalbiser          #+#    #+#             */
/*   Updated: 2024/04/22 11:36:44 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	reverse_rotate_both(t_stack **a, \
t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target && *a != cheapest_node)
		rrr(a, b);
	set_index(*a);
	set_index(*b);
}

static	void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (cheapest_node->previous && cheapest_node->target->previous)
		rr(a, b);
	set_index(*a);
	set_index(*b);
}

static	t_stack	*get_cheapest(t_stack *stack)
{
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median) && \
	!(cheapest_node->target->above_median))
		reverse_rotate_both(a, b, cheapest_node);
	prep_to_push(a, cheapest_node, 'a');
	prep_to_push(b, cheapest_node->target, 'b');
	pb(a, b, 1);
}
