/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcesar-d <rcesar-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:17:18 by rcesar-d          #+#    #+#             */
/*   Updated: 2024/11/11 12:01:40 by rcesar-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	r_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
	second_last->next = NULL;
	last->prev = NULL;
}

void	rra(t_stack **a)
{
	r_rotate(a);
	write (1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	r_rotate(b);
	write (1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	r_rotate(a);
	r_rotate(b);
	write (1, "rrr\n", 4);
}
