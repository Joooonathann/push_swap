/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:41:56 by jalbiser          #+#    #+#             */
/*   Updated: 2024/04/04 13:53:33 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack **a, t_stack **b, int print)
{
	t_stack	*first;

	if ((count_stack(*a) < 2) || (count_stack(*b) < 2))
		return ;
	rotate_pile(a, 1, 0);
	rotate_pile(b, 2, 0);
	ft_putendl_fd("rb", 1);
}
