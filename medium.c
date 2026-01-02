/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitani <mitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 23:19:47 by mitani            #+#    #+#             */
/*   Updated: 2026/01/02 03:40:00 by mitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isqrt(int n)
{
	int	i;

	if (n < 0)
		return (-1);
	i = 0;
	while (i * i <= n)
		i++;
	return (i - 1);
}

int	get_chunk_count(int stack_size)
{
	int	chunks;

	if (stack_size <= 3)
		return (1);
	chunks = ft_isqrt(stack_size);
	if (chunks < 2)
		chunks = 2;
	return (chunks);
}

int	get_chunk_size(int stack_size)
{
	int	chunk_count;

	chunk_count = get_chunk_count(stack_size);
	return ((stack_size + chunk_count - 1) / chunk_count);
}

int	*calculate_chunk_ranges(int stack_size, int *chunk_count)
{
	int	*ranges;
	int	i;
	int	chunk_size;

	*chunk_count = get_chunk_count(stack_size);
	chunk_size = get_chunk_size(stack_size);
	ranges = malloc((*chunk_count + 1) * sizeof(int));
	if (!ranges)
		return (NULL);
	i = 0;
	while (i < *chunk_count)
	{
		ranges[i] = i * chunk_size;
		i++;
	}
	ranges[*chunk_count] = stack_size;
	return (ranges);
}

int	find_element_position(t_list *stack, int rank)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (*(int *)stack->content == rank)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}

void	push_chunk_to_b(t_list **stack_a, t_list **stack_b, int min_rank,
	int max_rank, char **operations)
{
	int	pos;
	int	size;
	int	rotations;

	(void)max_rank;
	size = ft_lstsize(*stack_a);
	while (ft_lstsize(*stack_a) > 0)
	{
		pos = find_element_position(*stack_a, min_rank);
		if (pos == -1)
			break ;
		if (pos <= size / 2)
		{
			while (pos-- > 0)
			{
				rotate(stack_a);
				ft_strjoin_sep(operations, "ra", "\n");
			}
		}
		else
		{
			rotations = size - pos;
			while (rotations-- > 0)
			{
				rev_rotate(stack_a);
				ft_strjoin_sep(operations, "rra", "\n");
			}
		}
		push(stack_a, stack_b);
		ft_strjoin_sep(operations, "pb", "\n");
		size = ft_lstsize(*stack_a);
		min_rank++;
	}
}

int	is_chunk_sorted(t_list *stack_b, int min_rank, int max_rank)
{
	int	prev_rank;
	int	current_rank;

	prev_rank = -1;
	while (stack_b)
	{
		current_rank = *(int *)stack_b->content;
		if (current_rank < min_rank || current_rank > max_rank)
		{
			stack_b = stack_b->next;
			continue ;
		}
		if (prev_rank != -1 && current_rank != prev_rank + 1)
			return (0);
		prev_rank = current_rank;
		stack_b = stack_b->next;
	}
	return (1);
}

void	rotate_to_chunk_max(t_list **stack_b, int min_rank, int max_rank,
	char **operations)
{
	int	pos;
	int	max_pos;
	int	size;
	int	rotations;
	t_list	*temp;

	(void)min_rank;
	temp = *stack_b;
	pos = 0;
	max_pos = -1;
	size = ft_lstsize(*stack_b);
	while (temp)
	{
		if (*(int *)temp->content == max_rank)
		{
			max_pos = pos;
			break ;
		}
		temp = temp->next;
		pos++;
	}
	if (max_pos == -1 || max_pos == 0)
		return ;
	if (max_pos <= size / 2)
	{
		while (max_pos-- > 0)
		{
			rotate(stack_b);
			ft_strjoin_sep(operations, "rb", "\n");
		}
	}
	else
	{
		rotations = size - max_pos;
		while (rotations-- > 0)
		{
			rev_rotate(stack_b);
			ft_strjoin_sep(operations, "rrb", "\n");
		}
	}
}

void	push_chunk_to_a(t_list **stack_a, t_list **stack_b, int min_rank,
	int max_rank, char **operations)
{
	int	current_rank;
	int	chunk_size;

	chunk_size = (max_rank - min_rank) + 1;
	while (chunk_size > 0)
	{
		current_rank = *(int *)(*stack_b)->content;
		if (current_rank >= min_rank && current_rank <= max_rank)
		{
			push(stack_b, stack_a);
			ft_strjoin_sep(operations, "pa", "\n");
			chunk_size--;
		}
		else
		{
			rotate(stack_b);
			ft_strjoin_sep(operations, "rb", "\n");
		}
	}
}

void	medium_algorithm(t_list **stack_a, t_list **stack_b, char **operations)
{
	t_list	*ranked_a;
	t_list	*temp;
	t_list	*orig_a;
	int	*ranges;
	int	chunk_count;
	int	i;
	int	min_rank;
	int	max_rank;
	int	stack_size;

	if (!stack_a || !*stack_a)
		return ;
	stack_size = ft_lstsize(*stack_a);
	temp = *stack_a;
	ranked_a = NULL;
	orig_a = NULL;
	while (temp)
	{
		ft_lstadd_back(&ranked_a, create_node(*(int *)temp->content));
		ft_lstadd_back(&orig_a, create_node(*(int *)temp->content));
		temp = temp->next;
	}
	rank_stack(&ranked_a);
	*stack_a = ranked_a;
	ranges = calculate_chunk_ranges(stack_size, &chunk_count);
	if (!ranges)
		return ;
	i = 0;
	while (i < chunk_count)
	{
		min_rank = ranges[i];
		max_rank = ranges[i + 1] - 1;
		push_chunk_to_b(stack_a, stack_b, min_rank, max_rank, operations);
		i++;
	}
	i = chunk_count - 1;
	while (i >= 0)
	{
		min_rank = ranges[i];
		max_rank = ranges[i + 1] - 1;
		if (is_chunk_sorted(*stack_b, min_rank, max_rank))
			rotate_to_chunk_max(stack_b, min_rank, max_rank, operations);
		push_chunk_to_a(stack_a, stack_b, min_rank, max_rank, operations);
		i--;
	}
	ft_lstclear(&orig_a, free);
	free(ranges);
}
