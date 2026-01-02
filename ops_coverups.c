/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_coverups.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfakih <mfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 15:23:58 by mfakih            #+#    #+#             */
/*   Updated: 2026/01/02 15:28:20 by mfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_list **stack_a, t_list **stack_b, char **ops)
{
	push(stack_a, stack_b);
	ft_strjoin_sep(ops, "pb", "\n");
}

void	pa(t_list **stack_a, t_list **stack_b, char **ops)
{
	push(stack_b, stack_a);
	ft_strjoin_sep(ops, "pa", "\n");
}

void	pb_rb(t_list **stack_a, t_list **stack_b, char **ops)
{
	push(stack_a, stack_b);
	ft_strjoin_sep(ops, "pb", "\n");
	rotate(stack_b);
	ft_strjoin_sep(ops, "rb", "\n");
}

void	ra(t_list **stack_a, char **ops)
{
	rotate(stack_a);
	ft_strjoin_sep(ops, "ra", "\n");
}

void	rb(t_list **stack_b, char **ops)
{
	rotate(stack_b);
	ft_strjoin_sep(ops, "rb", "\n");
}
