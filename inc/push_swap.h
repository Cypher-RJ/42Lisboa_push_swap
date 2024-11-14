/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcesar-d <rcesar-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:35:23 by rcesar-d          #+#    #+#             */
/*   Updated: 2024/11/11 11:59:15 by rcesar-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdint.h>

typedef struct s_stack
{
	long			nbr;
	int				index;
	int				push_cost;
	int				above_median;
	int				cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

void	ss(t_stack **a, t_stack **b);
void	sb(t_stack **b);
void	sa(t_stack **a);
void	pa(t_stack **b, t_stack **a);
void	pb(t_stack **a, t_stack **b);
long	ft_atol(const char *nptr);
void	rr(t_stack **a, t_stack **b);
void	rb(t_stack **b);
void	ra(t_stack **a);
void	rrr(t_stack **a, t_stack **b);
void	rrb(t_stack **b);
void	rra(t_stack **a);
int		syntax_error(char *n);
int		dup_error(t_stack *a, int n);
void	free_stack(t_stack **s);
void	free_errors(t_stack **a, t_stack **b);
void	sort_three(t_stack **a);
void	move_ab(t_stack **a, t_stack **b);
void	move_ba(t_stack **a, t_stack **b);
void	min_top(t_stack **a);
void	sort(t_stack **a, t_stack **b);
void	index_s(t_stack *s);
void	set_cheap(t_stack *s);
void	init_na(t_stack *a, t_stack *b);
void	init_nb(t_stack *a, t_stack *b);
void	init_sa(t_stack **a, t_stack **b, char **av);
t_stack	*get_cheap(t_stack *s);
void	push_init(t_stack **s, t_stack *up_node, char s_name);
int		stack_size(t_stack *s);
t_stack	*satck_last(t_stack *s);
int		check_sorted(t_stack *s);
t_stack	*find_min(t_stack *s);
t_stack	*find_max(t_stack *s);
int		main(int ac, char **av);
void	ft_bzero(void *s, size_t n);

#endif