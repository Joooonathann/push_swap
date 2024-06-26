/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:06:33 by jalbiser          #+#    #+#             */
/*   Updated: 2024/04/22 11:35:30 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack **a, t_stack **b)
{
	if (!is_sorted(*a))
	{
		if (count_stack(*a) == 1)
			return ;
		else if (count_stack(*a) == 2)
			sa(a, 1);
		else if (count_stack(*a) == 3)
			sort_three(a);
		else if (count_stack(*a) > 3)
			sort_big(a, b);
	}
}
