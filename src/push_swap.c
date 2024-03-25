/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:57:01 by jalbiser          #+#    #+#             */
/*   Updated: 2024/03/25 15:32:05 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_stack	*ft_add_stack(int n, t_stack **lst)
{
	t_stack	*result;
	t_stack *last;

	result = malloc(sizeof(t_stack));
	if (!result)
		return (NULL);
	last = *lst;
    while (last && last->next)
        last = last->next;
	result->number = n;
	result->previous = *lst;
	result->next = NULL;
	 if (!last)
        *lst = result;
    else
        last->next = result;
	return (result);
}

t_stack	*ft_create_stack(char **argv, int i)
{
	t_stack	*result;

	result = NULL;
	while (argv[i])
	{
		ft_add_stack(ft_atoi(argv[i]), &result);
		i++;
	}
	return (result);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc > 2)
	{
		ft_verify(argv, 1);
		a = ft_create_stack(argv, 1);
	}
	else if (argc == 2)
	{
		ft_verify(ft_split(argv[1], ' '), 0);
		a = ft_create_stack(ft_split(argv[1], ' '), 0);
	}
	else
		return (1);
		int z = 0;
	while (z != 2)
	{
		printf("%d\n", a->number);
		a = a->next;
		z++;
	}
	printf("\n\n");
	printf("%d\n", a->previous->number);
	return (0);
}
