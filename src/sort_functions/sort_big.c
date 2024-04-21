/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:05:12 by jalbiser          #+#    #+#             */
/*   Updated: 2024/04/15 10:49:57 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <limits.h>

void	swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	sort_array(int arr[], int n)
{
	int i;
	int j;
	int min_idx;

	i = 0;
	while (i < n - 1)
	{
		min_idx = i;
		j = i + 1;
		while (j < n)
		{
			if (arr[j] < arr[min_idx])
				min_idx = j;
			j++;
		}
		swap(&arr[min_idx], &arr[i]);
		i++;
	}
}

int	median_stack(t_stack *stack)
{
	int values[count_stack(stack)];
	int i;

	i = 0;
	while (stack)
	{
		values[i++] = stack->number;
		stack = stack->next;
	}
	sort_array(values, i);
	return (values[i / 2]);
}

int find_smallest(t_stack *stack)
{
    if (!stack) {
        printf("Error: Stack is empty.\n");
        return INT_MIN;
    }

    int smallest = stack->number;

    while (stack) {
        if (stack->number < smallest) {
            smallest = stack->number;
        }
        stack = stack->next;
    }

    return smallest;
}


int	counting_step_one(t_stack *stack, int median)
{
	int	i, b;
	t_stack *tmp;

	i = 0;
	b = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->number <= median)
			break ;
		tmp = tmp->next;
		i++;
	}
	while (stack->next)
		stack = stack->next;
	while (stack)
	{
		if (stack->number <= median)
			break ;
		stack = stack->previous;
		b++;
	}
	if (i <= b)
		return (1);
	return (0);
}

int	counting_last(t_stack *stack, int n)
{
	int	i, b;
	t_stack *tmp;

	i = 0;
	b = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->number == n)
			break ;
		tmp = tmp->next;
		i++;
	}
	while (stack->next)
		stack = stack->next;
	while (stack)
	{
		if (stack->number == n)
			break ;
		stack = stack->previous;
		b++;
	}
	if (i <= b)
		return (1);
	return (0);
}

void sort_big(t_stack **a, t_stack **b)
{
	int size = count_stack(*a);
	int median = median_stack(*a);

	if (is_sorted(*a))
		return ;
    while (size--)
    {
        if ((*a)->number <= median)
            pb(a, b, 1);
        else
		{
			if (counting_step_one(*a, median))
				ra(a, 1);
			else
				rra(a, 1);
		}
    }
	int stop = (*a)->number;
	while (count_stack(*a))
    {
        if ((*a)->number == find_smallest(*a))
            pb(a, b, 1);
        else
		{
			if (counting_last(*a, find_smallest(*a)))
				ra(a, 1);
			else
				rra(a, 1);
		}
    }
	while ((*b)->number != stop)
		pa(a, b, 1);
	while (count_stack(*b))
    {
        if ((*b)->number == find_biggest(*b))
            pa(a, b, 1);
        else
		{
			if (counting_last(*b, find_biggest(*b)))
				rb(b, 1);
			else
				rrb(b, 1);
		}
    }
}
