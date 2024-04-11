/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:00:45 by jalbiser          #+#    #+#             */
/*   Updated: 2024/04/11 10:39:59 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack **a, t_stack **b)
{
	if (!*a || !*b)
		return ;
	if (count_stack(*a) < 2 || count_stack(*b) < 2)
		return ;
	sa(a, 0);
	sb(b, 0);
	ft_putendl_fd("ss", 1);
}
