/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfakih <mfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 00:32:43 by mitani            #+#    #+#             */
/*   Updated: 2025/12/30 18:42:12 by mfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_list *stack)
{
	int	max;
	int	*value;
	int	bits;

	max = 0;
	bits = 0;
	while (stack)
	{
		value = stack->content;
		if ((*value > 0 && *value > max))
		{
			max = *value;
		}
		stack = stack->next;
	}
	while ((1 << bits) <= max)
		bits++;
	return (bits);
}

int	get_ith_bit(int content, int i)
{
	return ((content >> i) & 1);
}

int	indexx(int value, int *array, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (array[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	rank_stack(t_list **stack_a)
{
	int		i;
	int		len;
	int		*nbs;
	t_list	*n;

	i = 0;
	n = *stack_a;
	nbs = malloc(ft_lstsize(*stack_a) * sizeof(int));
	if (!nbs)
		return ;
	while (n)
	{
		nbs[i++] = *(int *)(n -> content);
		n = n -> next;
	}
	len = i;
	sort_int_tab(nbs, len);
	n = *stack_a;
	while (n)
	{
		(*(int *)((n)-> content)) = indexx(*(int *)((n)-> content), nbs, len);
		n = n -> next;
	}
	free (nbs);
}

void	complex_algorithm(t_list **stack_a, t_list **stack_b, char **ops)
{
	int	i;
	int	j;
	int	max_bits;

	rank_stack(stack_a);
	max_bits = get_max_bits(*stack_a);
	i = -1;
	while (++i < max_bits)
	{
		j = ft_lstsize(*stack_a);
		while (j-- > 0)
		{
			if (!get_ith_bit(*(int *)(*stack_a)->content, i))
			{
				push(stack_a, stack_b);
				ft_strjoin_sep(ops, "pb", "\n");
			}
			else
			{
				rotate(stack_a);
				ft_strjoin_sep(ops, "ra", "\n");
			}
		}
		push_back_to_a(stack_a, stack_b, ops);
	}
}
