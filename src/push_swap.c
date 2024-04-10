/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:57:01 by jalbiser          #+#    #+#             */
/*   Updated: 2024/04/10 15:37:34 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	printlist(t_stack *stack)
{
	if (!stack)
	{
		printf("NULL\n");
		return ;
	}
	while (stack)
	{
		printf("%d ", stack->number);
		stack = stack->next;
	}
	printf("\n");
}

void	create_node(int number, t_stack **stack)
{
	t_stack	*node;
	t_stack	*tmp;

	node = malloc(sizeof(t_stack));
	if (!node)
	{
		clear_stack(stack);
		exit(1);
	}
	node->number = number;
    node->next = NULL;
    node->previous = NULL;
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

t_stack	*create_stack(char **argv, int i)
{
	t_stack	*result;

	result = NULL;
	while (argv[i])
	{
		create_node(ft_atoi(argv[i]), &result);
		i++;
	}
	return (result);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc > 2)
	{
		ft_verify(argv, 1);
		a = create_stack(argv, 1);
	}
	else if (argc == 2)
	{
		ft_verify(ft_split(argv[1], ' '), 0);
		a = create_stack(ft_split(argv[1], ' '), 0);
	}
	else
		return (1);

	printf("A: "); printlist(a);
	printf("B: "); printlist(b);

	sa(&a, 1);
	pb(&a, &b, 1);
	pb(&a, &b, 1);
	pb(&a, &b, 1);
	ra(&a, 1);
	rb(&b, 1);
	rrr(&a, &b);
	sa(&a, 1);
	pa(&a, &b, 1);
	pa(&a, &b, 1);
	pa(&a, &b, 1);

	printf("A: "); printlist(a);
	printf("B: "); printlist(b);

	clear_stack(&a);
	clear_stack(&b);
	return (0);
}
