/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:28:47 by jalbiser          #+#    #+#             */
/*   Updated: 2024/04/10 15:28:56 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_stack(int n, t_stack **stack)
{
	t_stack	*result;
	t_stack *last;

	result = malloc(sizeof(t_stack));
	if (!result)
		return ;
	last = *stack;
    while (last && last->next)
        last = last->next;
	result->number = n;
	result->previous = *stack;
	result->next = NULL;
	if (!last)
        *stack = result;
    else
        last->next = result;
}