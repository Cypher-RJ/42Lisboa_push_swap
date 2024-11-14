/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcesar-d <rcesar-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:27:28 by rcesar-d          #+#    #+#             */
/*   Updated: 2024/11/11 12:02:58 by rcesar-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	index_s(t_stack *s)
{
	size_t	i;
	size_t	mid;

	i = 0;
	if (!s)
		return ;
	mid = stack_size(s) / 2;
	while (s)
	{
		s->index = i;
		if (i <= mid)
			s->above_median = 1;
		else
			s->above_median = 0;
		s = s->next;
		i++;
	}
}

static void	target_a(t_stack *a, t_stack *b)
{
	long	best_match;
	t_stack	*index_b;
	t_stack	*target;

	while (a)
	{
		best_match = LONG_MIN;
		index_b = b;
		while (index_b)
		{
			if (index_b->nbr < a->nbr && index_b->nbr > best_match)
			{
				best_match = index_b->nbr;
				target = index_b;
			}
			index_b = index_b->next;
		}
		if (best_match == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target;
		a = a->next;
	}
}

static void	cost_a(t_stack *a, t_stack *b)
{
	size_t	i_a;
	size_t	i_b;

	i_a = stack_size(a);
	i_b = stack_size(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = i_a - (a->index);
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += i_b - a->target_node->index;
		a = a->next;
	}
}

void	set_cheap(t_stack *s)
{
	long	cheap_value;
	t_stack	*cheap_node;

	if (!s)
		return ;
	cheap_value = LONG_MAX;
	while (s)
	{
		if (s->push_cost < cheap_value)
		{
			cheap_value = s->push_cost;
			cheap_node = s;
		}
		s = s->next;
	}
	cheap_node->cheapest = 1;
}

void	init_na(t_stack *a, t_stack *b)
{
	index_s(a);
	index_s(b);
	target_a(a, b);
	cost_a(a, b);
	set_cheap(a);
}
