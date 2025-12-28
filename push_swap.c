/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfakih <mfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 22:14:11 by mfakih            #+#    #+#             */
/*   Updated: 2025/12/27 18:10:33 by mfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		bench;
	char	*comp;
	t_list	*stack_a;

	stack_a = validate(argc, argv, &bench, &comp);
	if (!stack_a)
		return (free(comp), 0);
	ft_lstiter(stack_a, print_content);
	ft_printf(1, "the output of the simple alg is: %s", simple_algorithm(&stack_a));
	ft_printf(1," the sorted content is:\n");
	ft_lstiter(stack_a, print_content);
	ft_lstclear(&stack_a, free);
	return (free(comp), 0);
}
