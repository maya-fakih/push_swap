/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitani <mitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 00:32:43 by mitani            #+#    #+#             */
/*   Updated: 2025/12/30 03:00:38 by mitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_list *stack)
{
	int	max;
	int	*content;
	int	bits;

	max = 0;
	while (stack)
	{
		content = stack->content;
		if ((*content > 0 && *content > max) || (*content < 0 && -*content > max))
			max = (*content > 0) ? *content : -*content;
		stack = stack->next;
	}
	bits = 0;
	while ((1 << bits) <= max)
		bits++;
	return (bits);
}

void    complex_algorithm(t_list **stack_a, t_list **stack_b, char **operations)
{
	int	i;
	int	j;
	int	content;
	int	max_bits;

	max_bits = get_max_bits(*stack_a);
	i = 0;
	while (i < max_bits)
    {
        j = ft_lstsize(*stack_a);
        while (j-- > 0)
        {
            content = *(int *)(*stack_a)->content;
            if (!get_ith_bit(content, i))
            {
                push(stack_a, stack_b);
                ft_strjoin_sep(operations, "pb", "\n");
            }
            else
            {
                rotate(stack_a);
                ft_strjoin_sep(operations, "ra", "\n");
            }
        }
		while (ft_lstsize(*stack_b) > 0)
		{
			push(stack_b, stack_a);
			ft_strjoin_sep(operations, "pa", "\n");
		}
        i++;
    }
}