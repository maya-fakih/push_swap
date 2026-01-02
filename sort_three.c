/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfakih <mfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:59:13 by mfakih            #+#    #+#             */
/*   Updated: 2026/01/02 19:01:00 by mfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_rra(t_list **stack, char **ops)
{
	swap(stack);
	rev_rotate(stack);
	ft_strjoin_sep(ops, "sa\nrra", "\n");
}

void	sa_ra(t_list **stack, char **ops)
{
	swap(stack);
	rotate(stack);
	ft_strjoin_sep(ops, "sa\nra", "\n");
}

void	sa(t_list **stack, char **ops)
{
	swap(stack);
	ft_strjoin_sep(ops, "sa", "\n");
}

void	sort_three(t_list **stack, char **ops)
{
	int	a;
	int	b;
	int	c;

	a = *(int *)(*stack)->content;
	b = *(int *)(*stack)->next->content;
	c = *(int *)(*stack)->next->next->content;
	if (a > b && a > c)
	{
		if (b < c)
			ra(stack, ops);
		else
			sa_rra(stack, ops);
		return ;
	}
	else if (a < b && a < c)
	{
		if (b > c)
			sa_ra(stack, ops);
		return ;
	}
	if (a > b)
		sa(stack, ops);
	else
		rra(stack, ops);
}
