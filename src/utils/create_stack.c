/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:03:42 by jalbiser          #+#    #+#             */
/*   Updated: 2024/04/11 10:19:14 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
