/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:28:10 by jalbiser          #+#    #+#             */
/*   Updated: 2024/04/10 15:28:17 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(char **argv, int i)
{
	t_stack	*result;

	result = NULL;
	while (argv[i])
	{
		add_stack(ft_atoi(argv[i]), &result);
		i++;
	}
	return (result);
}