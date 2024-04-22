/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:05:12 by jalbiser          #+#    #+#             */
/*   Updated: 2024/04/22 11:35:19 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	min_on_top(t_stack **a)
{
	t_stack	*min_node;

	min_node = find_min(*a);
	while (min_node->previous)
	{
		if (min_node->above_median)
			ra(a, 1);
		else
			rra(a, 1);
	}
}

static void	move_b_to_a(t_stack **a, t_stack **b)
{
	prep_to_push(a, (*b)->target, 'a');
	pa(a, b, 1);
}

void	sort_big(t_stack **a, t_stack **b)
{
	if (count_stack(*a) > 3 && !is_sorted(*a))
		pb(a, b, 1);
	if (count_stack(*a) > 3 && !is_sorted(*a))
		pb(a, b, 1);
	while (count_stack(*a) > 3 && !is_sorted(*a))
	{
		init_node_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_node_b(*a, *b);
		move_b_to_a(a, b);
	}
	set_index(*a);
	min_on_top(a);
}
