/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:52:40 by jalbiser          #+#    #+#             */
/*   Updated: 2024/04/10 15:36:57 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack **a, t_stack **b)
{
	if ((count_stack(*a) < 2) || (count_stack(*b) < 2))
		return ;
	rotate_reverse_pile(a, 1, 0);
	rotate_reverse_pile(b, 2, 0);
	ft_putendl_fd("rrr", 1);
}