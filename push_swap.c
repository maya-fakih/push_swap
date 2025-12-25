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

void	check_flags(char **argv, int *show_bench, char **complexity, int *i)
{
	*i = 1;
	*show_bench = 0;
	*complexity = ft_strdup("--adaptive");
	if (argv[*i] && ft_strlen(argv[*i]) == 7
		&& (ft_strncmp(argv[*i], "--bench", ft_strlen(argv[*i])) == 0))
	{
		*show_bench = 1;
		(*i)++;
	}
	if (argv[*i] && ((ft_strlen(argv[*i]) == 8
				&& (ft_strncmp(argv[*i], "--simple", 8) == 0
					|| ft_strncmp(argv[*i], "--medium", 8) == 0))
			|| (ft_strlen(argv[*i]) == 9
				&& ft_strncmp(argv[*i], "--complex", 9) == 0)
			|| (ft_strlen(argv[*i]) == 10
				&& ft_strncmp(argv[*i], "--adaptive", 10) == 0)))
	{
		free(*complexity);
		*complexity = ft_strdup(argv[*i]);
		(*i)++;
	}
}

int	parse_input(int *i, char **argv, char **nbs)
{
	int		j;

	j = -1;
	*nbs = ft_strdup("\0");
	while (argv[*i])
	{
		ft_strjoin_sep(nbs, argv[*i], ' ');
		(*i)++;
	}
	while (*nbs[++j])
	{
		if (*nbs[j] != ' ' && *nbs[j] != '+' && *nbs[j] != '-'
			&& !ft_isdigit(*nbs[j]))
			return (free(*nbs), -1);
		if ((j > 0) && (*nbs[j +1] != '\0')
			&& (*nbs[j] == '-' || *nbs[j] == '+')
			&& ((*nbs[j -1] != ' ') || (!ft_isdigit(*nbs[j +1]))))
			return (free(*nbs), -1);
	}
	if ((j > 0) && (*nbs[j] == 0) && (*nbs[j - 1] == '+' || *nbs[j - 1] == '-'))
		return (free(*nbs), -1);
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	int		bench;
	char	*complexity;
	char	*nbs;

	if (argc < 2)
		return (ft_printf(2, "Error\n"), 0);
	check_flags(argv, &bench, &complexity, &i);
	if (parse_input(&i, argv, &nbs) == -1)
		return (ft_printf(2, "Error\n"), 0);
	free (nbs);
	free (complexity);
	return (0);
}
