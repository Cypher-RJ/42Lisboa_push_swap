/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcesar-d <rcesar-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:14:31 by rcesar-d          #+#    #+#             */
/*   Updated: 2024/11/14 09:15:49 by rcesar-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	append_node(t_stack **s, int n)
{
	t_stack	*node;
	t_stack	*last;

	if (!s)
		return ;
	node = malloc(sizeof(t_stack));
	if (node != NULL)
		ft_bzero(node, sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	if (!(*s))
	{
		*s = node;
		node->prev = NULL;
	}
	else
	{
		last = satck_last(*s);
		last->next = node;
		node->prev = last;
	}
}

void	init_sa(t_stack **a, t_stack **b, char **av)
{
	long	n;
	int		i;

	i = 0;
	while (av[i])
	{
		if (syntax_error(av[i]))
			free_errors(a, b);
		n = ft_atol(av[i]);
		if (n < INT_MIN || n > INT_MAX)
			free_errors(a, b);
		if (dup_error(*a, (int)n))
			free_errors(a, b);
		append_node(a, (int)n);
		i++;
	}
}

t_stack	*get_cheap(t_stack *s)
{
	if (!s)
		return (NULL);
	while (s)
	{
		if (s->cheapest)
			return (s);
		s = s->next;
	}
	return (NULL);
}

void	push_init(t_stack **s, t_stack *up_node, char s_name)
{
	while (*s != up_node)
	{
		if (s_name == 'a')
		{
			if (up_node->above_median)
				ra(s);
			else
				rra(s);
		}
		else if (s_name == 'b')
		{
			if (up_node->above_median)
				rb(s);
			else
				rrb(s);
		}
	}
}
