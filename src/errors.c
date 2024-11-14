/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcesar-d <rcesar-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:49:15 by rcesar-d          #+#    #+#             */
/*   Updated: 2024/11/11 11:01:49 by rcesar-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	syntax_error(char *n)
{
	int	i;

	i = 1;
	if (!(n[0] == '+' || n[0] == '-' || (n[0] >= '0' && n[0] <= '9')))
		return (1);
	if ((n[0] == '+' || n[0] == '-') && !(n[i] >= '0' && n[i] <= '9'))
		return (1);
	while (n[i])
	{
		if (!(n[i] >= '0' && n[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	dup_error(t_stack *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_stack **s)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!s)
		return ;
	current = *s;
	while (current)
	{
		tmp = current->next;
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	*s = NULL;
}

void	free_errors(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
	write (2, "Error\n", 6);
	exit(1);
}
