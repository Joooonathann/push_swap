/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:51:41 by jalbiser          #+#    #+#             */
/*   Updated: 2024/04/22 11:33:38 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				number;
	int				index;
	int				push_cost;
	int				above_median;
	int				cheapest;
	struct s_stack	*target;
	struct s_stack	*previous;
	struct s_stack	*next;
}					t_stack;

void				ft_verify(char **argv, int start);
int					count_stack(t_stack *stack);
void				clear_stack(t_stack **stack);
void				pa(t_stack **a, t_stack **b, int print);
void				pb(t_stack **a, t_stack **b, int print);
void				ra(t_stack **a, int print);
void				rb(t_stack **b, int print);
void				rr(t_stack **a, t_stack **b);
void				rra(t_stack **a, int print);
void				rrb(t_stack **b, int print);
void				rrr(t_stack **a, t_stack **b);
void				sa(t_stack **a, int print);
void				sb(t_stack **b, int print);
void				ss(t_stack **a, t_stack **b);
void				sort_stack(t_stack **a, t_stack **b);
void				sort_three(t_stack **stack);
void				sort_two(t_stack **stack);
void				create_node(int number, t_stack **stack);
t_stack				*create_stack(char **argv, int i);
int					find_biggest(t_stack *stack);
int					is_sorted(t_stack *stack);
void				sort_big(t_stack **a, t_stack **b);
void				init_node_a(t_stack *a, t_stack *b);
void				init_node_b(t_stack *a, t_stack *b);
t_stack				*find_max(t_stack *stack);
t_stack				*find_min(t_stack *stack);
void				prep_to_push(t_stack **stack, t_stack *to_rotate,
						char stack_name);
void				move_a_to_b(t_stack **a, t_stack **b);
void				set_index(t_stack *stack);

#endif