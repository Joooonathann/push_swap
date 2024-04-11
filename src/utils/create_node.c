/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:03:09 by jalbiser          #+#    #+#             */
/*   Updated: 2024/04/11 11:42:24 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_node(int number, t_stack **stack)
{
	t_stack	*node;
	t_stack	*tmp;

	node = malloc(sizeof(t_stack));
	if (!node)
	{
		clear_stack(stack);
		free(node);
		exit(1);
	}
	node->number = number;
	node->next = NULL;
	node->previous = NULL;
	node->index = 0;
	if (!*stack)
		*stack = node;
	else
	{
		tmp = *stack;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = node;
		node->previous = tmp;
	}
}
