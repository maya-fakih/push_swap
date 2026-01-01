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

double compute_disorder(t_list *stack)
{
    int size = ft_lstsize(stack);
    if (size < 2)
        return 0.0;

    int mistakes = 0;
    int total_pairs = 0;

    t_list *i_node = stack;
    for (int i = 0; i < size - 1; i++)
    {
        t_list *j_node = i_node->next;
        for (int j = i + 1; j < size; j++)
        {
            total_pairs++;
            if (*(int *)i_node->content > *(int *)j_node->content)
                mistakes++;
            j_node = j_node->next;
        }
        i_node = i_node->next;
    }

    return (double)mistakes / (double)total_pairs;
}

void solve(double disorder, t_list **a, t_list **b, char **ops, const char *comp)
{
    if (ft_streq(comp, "--simple"))
        simple_algorithm(a, b, ops);
    else if (ft_streq(comp, "--medium"))
        return ; //medium_algorithm(a, b, ops);
    else if (ft_streq(comp, "--complex"))
        complex_algorithm(a, b, ops);
    else
    {
        // fallback: default adaptive behavior
        if (disorder < 0.2)
            simple_algorithm(a, b, ops);
        else if (disorder < 0.5)
            return ;//medium_algorithm(a, b, ops);
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
	double	disorder;

	operations = NULL;
	stack_b = NULL;
	stack_a = validate(argc, argv, &bench, &comp);
	if (!stack_a)
		return (free(comp), 0);
	disorder = compute_disorder(stack_a);
	ft_printf(1, "the complexity is: %s", comp);
	if (disorder == 0.0)
		return (free(comp), ft_lstclear(&stack_a, free), 0);
	solve(disorder, &stack_a, &stack_b, &operations, comp);
	ft_lstiter(stack_a, print_content);
	ft_printf(1, "the output is:\n%s", operations);
	ft_printf(1, "\nthe sorted content is:\n");
	ft_lstiter(stack_a, print_content);
	ft_lstclear(&stack_a, free);
	return (free(comp), free(operations), 0);
}

