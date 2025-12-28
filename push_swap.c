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

void	free_array(char **n)
{
	int	i;

	i = 0;
	if (!n)
		return ;
	while (n[i])
	{
		free (n[i]);
		i++;
	}
	free (n);
}

t_list	*validate(int argc, char **argv, int *bench, char **comp)
{
	int		i;
	char	*nbs;
	t_list	*stack_a;

	init(&i, bench, comp, &nbs);
	if (argc < 2)
		return (free(nbs), ft_printf(2, "Error no args\n"), NULL);
	check_flags(argv, bench, comp, &i);
	if (check_input(&i, argv, &nbs) == -1)
		return (ft_printf(2, "Error in numbers format\n"), NULL);
	stack_a = to_list(nbs);
	if (stack_a == NULL)
		return (free(nbs), ft_printf(2, "to list failed (dups or overflow)\n"), NULL);
	return (free(nbs), (stack_a));
}

t_list	*create_node(int content)
{
	int	*a;

	a = malloc(sizeof(int));
	*a = content;
	return (ft_lstnew((void *)(a)));
}

int		check_duplicates(t_list	*stack, int value)
{
	int	*current;

	if (!stack)
		return (0);
	while (stack)
	{
		current = (int *)(stack -> content);
		if (*current == value)
			return (1);
		stack = stack -> next;
	}
	return (0);
}

t_list	*to_list(char *nbs)
{
	t_list	*lst;
	int		i;
	int		content;
	int		overflow;
	char 	**n;

	lst = NULL;
	i = 0;
	n = ft_split(nbs, ' ');
	overflow = 0;
	if (!n)
		return (NULL);
	while (n[i])
	{
		content = ft_atoi_overflow(n[i], &overflow);
		if (overflow == 1)
			return (free_array(n), ft_lstclear(&lst, free), NULL);
		if (check_duplicates(lst, content) == 1)
			return (free_array(n), ft_lstclear(&lst, free), NULL);
		ft_lstadd_back(&lst, create_node(content));
		i++;
	}
	return (free_array(n), lst);
}

void	print_content(void *content)
{
	if (!content)
		return ;
	ft_printf(1,"%d\n", *(int *)content);
}

int	main(int argc, char **argv)
{
	int		bench;
	char	*comp;
	t_list	*stack_a;

	stack_a = validate(argc, argv, &bench, &comp);
	if (!stack_a)
		return (free(comp), 0);
	ft_printf(1, "%d\n", ft_lstsize(stack_a));
	ft_lstiter(stack_a, print_content);
	ft_lstclear(&stack_a, free);
	return (free(comp), 0);
}
