/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:05:12 by jalbiser          #+#    #+#             */
/*   Updated: 2024/04/11 11:50:02 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void ft_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void ft_bubblesort(int arr[], size_t size)
{
    size_t i = 0;
    size_t j;

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
	while(stack)
	{
		result[i] = stack->number;
		stack = stack->next;
		i++;
	}
	return (result);
}
void	init_index(int *tab, t_stack **stack)
{
	int	i;
	int	finish;
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
//sort_big est ma fonction pour trier une pile contenant plus de trois nombres
void	sort_big(t_stack **a, t_stack **b)
{
	int	*tab_a;

	tab_a = convert_tab(*a);
	ft_bubblesort(tab_a, count_stack(*a));
	init_index(tab_a, a);
	return ((void)*b);
}
