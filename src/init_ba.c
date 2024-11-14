/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ba.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcesar-d <rcesar-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:57:27 by rcesar-d          #+#    #+#             */
/*   Updated: 2024/11/11 12:03:07 by rcesar-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	target_b(t_stack *a, t_stack *b)
{
	long	best_match;
	t_stack	*index_a;
	t_stack	*target;

	while (b)
	{
		best_match = LONG_MAX;
		index_a = a;
		while (index_a)
		{
			if (index_a->nbr > b->nbr && index_a->nbr < best_match)
			{
				best_match = index_a->nbr;
				target = index_a;
			}
			index_a = index_a->next;
		}
		if (best_match == LONG_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target;
		b = b->next;
	}
}

void	init_nb(t_stack *a, t_stack *b)
{
	index_s(a);
	index_s(b);
	target_b(a, b);
}
