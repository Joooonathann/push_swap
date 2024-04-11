/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:00:09 by jalbiser          #+#    #+#             */
/*   Updated: 2024/04/11 10:39:49 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack **a, t_stack **b)
{
	if (count_stack(*a) < 2 || count_stack(*b) < 2)
		return ;
	rra(a, 0);
	rrb(b, 0);
	ft_putendl_fd("rrr", 1);
}
