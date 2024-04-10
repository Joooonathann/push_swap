/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:51:41 by jalbiser          #+#    #+#             */
/*   Updated: 2024/04/04 15:49:53 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>

typedef struct s_stack
{
	int				number;
	struct s_stack	*previous;
	struct s_stack	*next;
}	t_stack;

void	ft_verify(char **argv, int start);
int		count_stack(t_stack *stack);
void	rotate_pile(t_stack **stack, int pile, int print);
void	rotate_reverse_pile(t_stack **stack, int pile, int print);
void	push_stack(t_stack **a, t_stack **b, int pile, int print);
void	swap_top(t_stack **stack, int pile, int print);
void	rr(t_stack **a, t_stack **b, int print);
void	rrr(t_stack **a, t_stack **b, int pile, int print);
void	ss(t_stack **a, t_stack **b);

#endif