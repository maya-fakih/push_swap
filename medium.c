/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfakih <mfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:04:22 by mfakih            #+#    #+#             */
/*   Updated: 2026/01/03 09:48:28 by mfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_push_a(t_list **stack_a, t_list **stack_b, char **ops, int n)
{
	int	max;

	max = ft_lstsize(*stack_b) - 1;
	while (max >= 0)
	{
		if (find_element_position(*stack_b, max) <= n)
		{
			while (*(int *)((*stack_b)-> content) != max)
				rb(stack_b, ops);
			pa(stack_a, stack_b, ops);
		}
		if (find_element_position(*stack_b, max) > n)
		{
			while (*(int *)((*stack_b)-> content) != max)
				rrb(stack_b, ops);
			pa(stack_a, stack_b, ops);
		}
		max--;
	}
}

void	medium_algorithm(t_list **stack_a, t_list **stack_b, char **ops)
{
	int	i;
	int	n;
	int	len;

	i = 0;
	n = ft_isqrt(ft_lstsize(*stack_a));
	rank_stack(stack_a);
	while (*stack_a)
	{
		len = ft_lstsize(*stack_a) + 1;
		while (--len)
		{
			if (*(int *)((*stack_a)-> content) <= (i) * n)
				pb(stack_a, stack_b, ops);
			else if (*(int *)((*stack_a)-> content) <= (i + 1) * n)
				pb_rb(stack_a, stack_b, ops);
			else
				ra(stack_a, ops);
		}
		i += 2;
	}
	sort_push_a(stack_a, stack_b, ops, n);
}
