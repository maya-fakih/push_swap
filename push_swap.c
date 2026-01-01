/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfakih <mfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 22:14:11 by mfakih            #+#    #+#             */
/*   Updated: 2025/12/30 11:19:24 by mfakih           ###   ########.fr       */
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

void	solve(t_list **a, t_list **b, char **ops, const char *comp)
{
	double	disorder;

	disorder = compute_disorder(*a);
	if (disorder == 0.0)
	{
		*ops = ft_strdup("");
		return ;
	}
	if (ft_streq(comp, "--simple"))
		simple_algorithm(a, b, ops);
	else if (ft_streq(comp, "--medium"))
		simple_algorithm(a, b, ops);
	else if (ft_streq(comp, "--complex"))
		complex_algorithm(a, b, ops);
	else
	{
		if (disorder < 0.2)
			simple_algorithm(a, b, ops);
		else if (disorder < 0.5)
			simple_algorithm(a, b, ops);
		else
			complex_algorithm(a, b, ops);
	}
}

int	main(int argc, char **argv)
{
	int		bench;
	char	*comp;
	char	*operations;
	t_list	*stack_a;
	t_list	*stack_b;

	operations = NULL;
	stack_b = NULL;
	stack_a = validate(argc, argv, &bench, &comp);
	if (!stack_a)
		return (free(comp), 0);
	ft_printf(1, "the complexity is: %s", comp);
	solve(&stack_a, &stack_b, &operations, comp);
	ft_lstiter(stack_a, print_content);
	ft_printf(1, "the output is:\n%s", operations);
	ft_printf(1, "\nthe sorted content is:\n");
	ft_lstiter(stack_a, print_content);
	ft_lstclear(&stack_a, free);
	return (free(comp), free(operations), 0);
}
