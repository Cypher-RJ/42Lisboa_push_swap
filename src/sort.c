/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcesar-d <rcesar-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:00:26 by rcesar-d          #+#    #+#             */
/*   Updated: 2024/11/11 10:56:37 by rcesar-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort(t_stack **a, t_stack **b)
{
	size_t	i;

	i = stack_size(*a);
	if (i-- > 3 && !check_sorted(*a))
		pb(a, b);
	if (i-- > 3 && !check_sorted(*a))
		pb(a, b);
	while (i-- > 3 && !check_sorted(*a))
	{
		init_na(*a, *b);
		move_ab(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nb(*a, *b);
		move_ba(a, b);
	}
	index_s(*a);
	min_top(a);
}
