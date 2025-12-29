/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitani <mitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 22:14:11 by mfakih            #+#    #+#             */
/*   Updated: 2025/12/27 18:31:24 by mitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	simple_algorithm(&stack_a, &stack_b, &operations);
	ft_printf(1, "the output of the simple alg is:\n %s", operations);
	ft_printf(1, "the sorted content is:\n");
	ft_lstiter(stack_a, print_content);
	ft_lstclear(&stack_a, free);
	return (free(comp), free(operations), 0);
}
