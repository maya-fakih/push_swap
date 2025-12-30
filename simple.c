/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfakih <mfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 21:55:35 by mfakih            #+#    #+#             */
/*   Updated: 2025/12/30 08:34:51 by mfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_value_in_list(t_list *stack, int *index)
{
	int	min;
	int	*content;
	int	pos;

	pos = 0;
	min = __INT_MAX__;
	while (stack)
	{
		content = stack -> content;
		if (*content < min)
		{
			min = *content;
			*index = pos;
		}
		stack = stack -> next;
		pos++;
	}
	return (min);
}

void	push_back_to_a(t_list **stack_a, t_list **stack_b, char **operations)
{
	while (ft_lstsize(*stack_b) != 0)
	{
		push(stack_b, stack_a);
		ft_strjoin_sep(operations, "pa", "\n");
	}
}

void	simple_algorithm(t_list **stack_a, t_list **stack_b, char **operations)
{
	int		min_value;
	int		index;
	int		content;

	while (ft_lstsize(*stack_a) > 1)
	{
		content = *(int *)(*stack_a)->content;
		min_value = min_value_in_list(*stack_a, &index);
		while (content != min_value && (index <= ft_lstsize(*stack_a) / 2))
		{
			rotate(stack_a);
			ft_strjoin_sep(operations, "ra", "\n");
			content = *(int *)(*stack_a)->content;
		}
		while (content != min_value && (index > ft_lstsize(*stack_a) / 2))
		{
			rev_rotate(stack_a);
			ft_strjoin_sep(operations, "rra", "\n");
			content = *(int *)(*stack_a)->content;
		}
		push(stack_a, stack_b);
		ft_strjoin_sep(operations, "pb", "\n");
	}
	push_back_to_a(stack_a, stack_b, operations);
}
