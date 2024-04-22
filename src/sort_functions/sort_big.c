/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:05:12 by jalbiser          #+#    #+#             */
/*   Updated: 2024/04/22 09:27:18 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <limits.h>

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

void	set_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = count_stack(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		i++;
		stack = stack->next;
	}
}

static	void	set_cheapest_a(t_stack *stack)
{
	t_stack	*cheapest_node;
	long	cheapest_value;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = 1;
}

static	void	set_cost_a(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = count_stack(a);
	len_b = count_stack(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = len_a - (a->index);
		if (a->target->above_median)
			a->push_cost += a->target->index;
		else
			a->push_cost += len_b - (a->target->index);
		a = a->next;
	}
}

static	void	set_target_a(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	t_stack	*target_node;
	long	best_match_index;

	target_node = NULL;
	while (a)
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->number < a->number && \
			current_b->number > best_match_index)
			{
				best_match_index = current_b->number;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			a->target = find_max(b);
		else
			a->target = target_node;
		a = a->next;
	}
}
static	void	set_target_b(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long	best_match_index;

	target_node = NULL;
	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->number > b->number && \
			current_a->number < best_match_index)
			{
				best_match_index = current_a->number;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target = find_min(a);
		else
			b->target = target_node;
		b = b->next;
	}
}

void	init_node_b(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	set_target_b(a, b);
}
void	printliste(t_stack *stack)
{
	if (!stack)
	{
		printf("NULL\n");
		return ;
	}
	while (stack)
	{
		printf("%d => target = %p\n", stack->number, stack->target);
		stack = stack->next;
	}
	printf("\n");
}
void	init_node_a(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	printliste(a);
	printliste(b);
	set_target_a(a, b);
	printliste(a);
	printliste(b);
	set_cost_a(a, b);
	set_cheapest_a(a);
}
static	void	min_on_top(t_stack **a)
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

static	void	move_b_to_a(t_stack **a, t_stack **b)
{
	prep_to_push(a, (*b)->target, 'a');
	pa(a, b, 1);
}

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
	pb(b, a, 1);
}
void sort_big(t_stack **a, t_stack **b)
{
	if (count_stack(*a) > 3 && !is_sorted(*a))
		pb(b, a, 1);
	if (count_stack(*a) > 3 && !is_sorted(*a))
		pb(b, a, 1);
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
