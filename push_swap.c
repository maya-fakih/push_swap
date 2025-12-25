/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfakih <mfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 22:14:11 by mfakih            #+#    #+#             */
/*   Updated: 2025/12/24 22:14:13 by mfakih           ###   ########.fr       */
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

int	validate(int argc, char **argv, int *bench, char **comp)
{
	int		i;
	char	*nbs;
	char	**n;

	init(&i, bench, comp, &nbs);
	if (argc < 2)
		return (free(nbs), ft_printf(2, "Error no args\n"), -1);
	check_flags(argv, bench, comp, &i);
	if (check_input(&i, argv, &nbs) == -1)
		return (ft_printf(2, "Error in numbers format\n"), -1);
	n = check_duplicates(nbs);
	if (n == NULL)
		return (free(nbs),ft_printf(2, "found duplicates\n"), -1);
	return (free(nbs), free_array(n), 0);
}

int	main(int argc, char **argv)
{
	int		bench;
	char	*comp;

	if (validate(argc, argv, &bench, &comp) == -1)
		ft_printf(2, "validation error\n");
	return (free(comp), 0);
}
