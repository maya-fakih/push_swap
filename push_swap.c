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

char	**check_duplicates(char *nbs)
{
	char	**n;
	int		i;
	int		j;

	i = 0;
	n = ft_split(nbs, ' ');
	if (!n)
		return (ft_printf(2, "couldnt split\n"), NULL);
	while (n[i])
	{
		j = i + 1;
		while (n[j])
		{
			if ((ft_strncmp(n[i], n[j], ft_strlen(n[i])) == 0)
				&& ft_strlen(n[i]) == ft_strlen(n[j]))
				return (free_array(n), NULL);
			j++;
		}
		i++;
	}
	return (n);
}

t_list	*create_node(int content)
{
	int	*a;

	a = malloc(sizeof(int));
	*a = content;
	return (ft_lstnew((void *)(a)));
}

t_list	*to_list(const char *nbs)
{
	t_list	*lst;
	int		content;
	int		overflow;
	int		i;
	char	**n;

	lst = NULL;
	i = 0;
	n = ft_split(nbs, ' ');
	overflow = 0;
	if (!n)
		return (ft_printf(2, "couldnt split\n"), NULL);
	while (n[i])
	{
		content = ft_atoi_overflow(n[i], &overflow);
		if (overflow == 1)
			return (ft_lstclear(&lst, free), lst);
		ft_lstadd_back(&lst, create_node(content));
		i++;
	}
	return (lst);
}

t_list	*validate(int argc, char **argv, int *bench, char **comp)
{
	int		i;
	char	*nbs;
	char	**n;
	t_list	*lst;

	init(&i, bench, comp, &nbs);
	if (argc < 2)
		return (free(nbs), ft_printf(2, "Error no args\n"), NULL);
	check_flags(argv, bench, comp, &i);
	if (check_input(&i, argv, &nbs) == -1)
		return (ft_printf(2, "Error in numbers format\n"), NULL);
	n = check_duplicates(nbs);
	if (n == NULL)
		return (free(nbs), ft_printf(2, "found duplicates\n"), NULL);
	lst = to_list(nbs);
	return (free(nbs), free_array(n), lst);
}

int	main(int argc, char **argv)
{
	int		bench;
	char	*comp;
	t_list	*lst;

	lst = validate(argc, argv, &bench, &comp);
	if (lst == NULL)
		ft_printf(2, "validation error\n");
	return (free(comp), 0);
}
