/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcesar-d <rcesar-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:29:13 by rcesar-d          #+#    #+#             */
/*   Updated: 2024/11/11 10:56:18 by rcesar-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	rotate_ab(t_stack **a, t_stack **b, t_stack *cheap)
{
	while (*b != cheap->target_node && *a != cheap)
		rr(a, b);
	index_s(*a);
	index_s(*b);
}

static void	rr_ab(t_stack **a, t_stack **b, t_stack *cheap)
{
	while (*b != cheap->target_node && *a != cheap)
		rrr(a, b);
	index_s(*a);
	index_s(*b);
}

void	move_ab(t_stack **a, t_stack **b)
{
	t_stack	*cheap_node;

	cheap_node = get_cheap(*a);
	if (cheap_node->above_median && cheap_node->target_node->above_median)
		rotate_ab(a, b, cheap_node);
	else if (!(cheap_node->above_median)
		&& !(cheap_node->target_node->above_median))
		rr_ab(a, b, cheap_node);
	push_init(a, cheap_node, 'a');
	push_init(b, cheap_node->target_node, 'b');
	pb(a, b);
}

void	move_ba(t_stack **a, t_stack **b)
{
	push_init(a, (*b)->target_node, 'a');
	pa(b, a);
}

void	min_top(t_stack **a)
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}
