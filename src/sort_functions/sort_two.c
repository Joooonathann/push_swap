/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:05:57 by jalbiser          #+#    #+#             */
/*   Updated: 2024/04/11 11:09:34 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//sort_two est ma fonction pour trier une pile contenant deux nombres
void	sort_two(t_stack **stack)
{
	if (is_sorted(*stack))
		return ;
	sa(stack, 1);
}
