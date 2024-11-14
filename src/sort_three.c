/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcesar-d <rcesar-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:20:53 by rcesar-d          #+#    #+#             */
/*   Updated: 2024/11/11 10:55:38 by rcesar-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	*big_node;

	big_node = find_max(*a);
	if (big_node == *a)
		ra(a);
	else if ((*a)->next == big_node)
		rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
}
