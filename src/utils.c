/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcesar-d <rcesar-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:50:55 by rcesar-d          #+#    #+#             */
/*   Updated: 2024/11/11 10:59:32 by rcesar-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	stack_size(t_stack *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s)
	{
		s = s->next;
		i++;
	}
	return (i);
}

t_stack	*satck_last(t_stack *s)
{
	t_stack	*last;

	if (!s)
		return (NULL);
	while (s)
	{
		last = s;
		s = s->next;
	}
	return (last);
}

int	check_sorted(t_stack *s)
{
	if (!s)
		return (1);
	while (s->next)
	{
		if (s->nbr > s->next->nbr)
			return (0);
		s = s->next;
	}
	return (1);
}

t_stack	*find_min(t_stack *s)
{
	long	min;
	t_stack	*min_node;

	if (!s)
		return (NULL);
	min = LONG_MAX;
	while (s)
	{
		if (s->nbr < min)
		{
			min = s->nbr;
			min_node = s;
		}
		s = s->next;
	}
	return (min_node);
}

t_stack	*find_max(t_stack *s)
{
	long	max;
	t_stack	*max_node;

	if (!s)
		return (NULL);
	max = LONG_MIN;
	while (s)
	{
		if (s->nbr > max)
		{
			max = s->nbr;
			max_node = s;
		}
		s = s->next;
	}
	return (max_node);
}
