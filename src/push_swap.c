/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:57:01 by jalbiser          #+#    #+#             */
/*   Updated: 2024/04/11 11:49:05 by jalbiser         ###   ########.fr       */
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
		printf("%d->%d ", stack->index, stack->number);
		stack = stack->next;
	}
	printf("\n");
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
	printf("A: ");
	printlist(a);
	printf("B: ");
	printlist(b);
	sort_stack(&a, &b);
	printf("A: ");
	printlist(a);
	printf("B: ");
	printlist(b);
	clear_stack(&a);
	clear_stack(&b);
	return (0);
}
