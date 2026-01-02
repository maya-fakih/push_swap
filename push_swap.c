/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfakih <mfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 22:14:11 by mfakih            #+#    #+#             */
/*   Updated: 2026/01/02 16:08:23 by mfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_list *stack)
{
	int		mistakes;
	int		total_pairs;
	t_list	*i;
	t_list	*j;

	if (!stack || !stack->next)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	i = stack;
	while (i)
	{
		j = i->next;
		while (j)
		{
			total_pairs++;
			if (*(int *)i->content > *(int *)j->content)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	return ((double)mistakes / (double)total_pairs);
}

void	solve(t_list **a, double d, char **ops, const char *comp)
{
	t_list	*b;

	b = NULL;
	if (d == 0.0)
	{
		*ops = ft_strdup("");
		return ;
	}
	if (ft_streq(comp, "--simple"))
		simple_algorithm(a, &b, ops);
	else if (ft_streq(comp, "--medium"))
		medium_algorithm(a, &b, ops);
	else if (ft_streq(comp, "--complex"))
		complex_algorithm(a, &b, ops);
	else
	{
		if (d < 0.2)
			simple_algorithm(a, &b, ops);
		else if (d < 0.5)
			medium_algorithm(a, &b, ops);
		else
			complex_algorithm(a, &b, ops);
	}
}

void	print_bench(char *ops, char *comp, double d)
{
	double	p;

	p = d * 100;
	ft_printf(2, "[bench] disorder: %f%%\n", p);
	if (ft_streq(comp, "--simple"))
		ft_printf(2, "[bench] strategy: Simple / O(n²)\n");
	else if (ft_streq(comp, "--medium"))
		ft_printf(2, "[bench] strategy: Medium / O(n√n)\n");
	else if (ft_streq(comp, "--complex"))
		ft_printf(2, "[bench] strategy: Complex / O(n log n)\n");
	else
	{
		if (d < 0.2)
			ft_printf(2, "[bench] strategy: Adaptive / O(n²)\n");
		else if (d < 0.5)
			ft_printf(2, "[bench] strategy: Adaptive / O(n√n)\n");
		else
			ft_printf(2, "[bench] strategy: Adaptive / O(n log n)\n");
	}
	ft_printf(2, "[bench] total_ops: %i\n", total_ops(ops));
	ft_printf(2, "[bench] sa: %i sb:%i ss: %i pa: %i pb: %i\n", c_op(ops, "sa"),
		c_op(ops, "sb"), c_op(ops, "ss"), c_op(ops, "pa"), c_op(ops, "pb"));
	ft_printf(2, "[bench] ra: %i rb:%i rr: %i rra: %i rrb: %i rrr: %i\n",
		c_op(ops, "ra"), c_op(ops, "rb"), c_op(ops, "rr"), c_op(ops, "rra"),
		c_op(ops, "rrb"), c_op(ops, "rrr"));
}

int	main(int argc, char **argv)
{
	int		bench;
	char	*comp;
	char	*operations;
	double	disorder;
	t_list	*stack_a;

	operations = NULL;
	stack_a = validate(argc, argv, &bench, &comp);
	if (!stack_a)
		return (free(comp), 0);
	disorder = compute_disorder(stack_a);
	solve(&stack_a, disorder, &operations, comp);
	ft_printf(1, "%s", operations);
	if (bench == 1)
		print_bench(operations, comp, disorder);
	ft_lstclear(&stack_a, free);
	return (free(comp), free(operations), 0);
}
