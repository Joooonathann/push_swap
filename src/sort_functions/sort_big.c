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

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_bubblesort(int arr[], size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				ft_swap(&arr[j], &arr[j + 1]);
			}
			j++;
		}
		i++;
	}
}

int	*convert_tab(t_stack *stack)
{
	int	*result;
	int	i;

	result = malloc(sizeof(int) * count_stack(stack));
	if (!result)
		return (NULL);
	i = 0;
	while (stack)
	{
		result[i] = stack->number;
		stack = stack->next;
		i++;
	}
	return (result);
}
void	init_index(int *tab, t_stack **stack)
{
	int		i;
	int		finish;
	t_stack	*tmp;

	finish = count_stack(*stack);
	i = 0;
	while (i < finish)
	{
		tmp = *stack;
		while (tmp)
		{
			if (tmp->number == tab[i])
				tmp->index = i;
			tmp = tmp->next;
		}
		i++;
	}
}
int		ra_count(t_stack *a)
{
	int i;
	int	b;
	
	b = 0;
	i = (count_stack(a) / 2);
	while (a)
	{
		if (a->index <= i)
			return (b);
		a = a->next;
		b++;
	}
	return (b);
}

int		rra_count(t_stack *a)
{
	int i;
	int	b;
	
	b = 0;
	i = (count_stack(a) / 2);
	while (a->next != NULL)
		a = a->next;
	while (a)
	{
		if (a->index <= i)
			return (b);
		a = a->previous;
		b++;
	}
	return (b);
}
int count_rb(t_stack *b, int index)
{
    int count = 0;
    t_stack *tmp = b;
    while (tmp && tmp->index != index)
    {
        tmp = tmp->next;
        count++;
    }
    return count;
}

int count_rrb(t_stack *b, int index)
{
    int count = 0;
    t_stack *tmp = b;
	while (tmp->next != NULL)
		tmp = tmp->next;
    while (tmp && tmp->index != index)
    {
        tmp = tmp->previous;
        count++;
    }
    return count;
}

void	sort_stat(t_stack **a, t_stack **b)
{
	int i = (count_stack(*a) / 2);
	int d = 0;
	while (d < i)
	{
		if ((*a)->index < i)
		{
			pb(a, b, 1);
			d++;
		}
		else
		{
			if (ra_count(*a) <= rra_count(*a))
				ra(a, 1);
			else
				rra(a, 1);
		}
	}
	
	while (*a)
		pb(a, b, 1);





		
	int	z = count_stack(*b);
	while (z != 0)
	{
		while ((*b)->index != z - 1)
		{
			if (count_rb(*b, (z - 1)) <= count_rrb(*b, (z - 1)))
				rb(b, 1);
			else
				rrb(b, 1);
		}
		pa(a, b, 1);
		z--;
	}
}


// sort_big est ma fonction pour trier une pile contenant plus de trois nombres
void	sort_big(t_stack **a, t_stack **b)
{
	int	*tab_a;

	tab_a = convert_tab(*a);
	ft_bubblesort(tab_a, count_stack(*a));
	init_index(tab_a, a);
	sort_stat(a, b);
}
