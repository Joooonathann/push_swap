/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:57:01 by jalbiser          #+#    #+#             */
/*   Updated: 2024/04/04 13:29:21 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_add_stack(int n, t_stack **stack)
{
	t_stack	*result;
	t_stack *last;

	result = malloc(sizeof(t_stack));
	if (!result)
		return (NULL);
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
	return (0);
}
