/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfakih <mfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 14:30:45 by mfakih            #+#    #+#             */
/*   Updated: 2025/12/25 14:30:47 by mfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_flags(char **argv, int *show_bench, char **complexity, int *i)
{
	if (argv[*i] && ft_strlen(argv[*i]) == 7
		&& (ft_strncmp(argv[*i], "--bench", ft_strlen(argv[*i])) == 0))
	{
		*show_bench = 1;
		*i = *i + 1;
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
		*i = *i + 1;
	}
}

int	parse_input(int *i, char **argv, char **nbs)
{
	int		j;
	char	*s;

	j = -1;
	while (argv[*i])
	{
		ft_strjoin_sep(nbs, argv[*i], " ");
		if (!*nbs)
			return (-1);
		(*i)++;
	}
	s = *nbs;
	while (s[++j])
	{
		if (s[j] != ' ' && s[j] != '+' && s[j] != '-'
			&& !ft_isdigit(s[j]))
			return (free(s), -1);
		if ((j > 0)
			&& (s[j] == '-' || s[j] == '+')
			&& ((s[j - 1] != ' ') || (!ft_isdigit(s[j + 1]))))
			return (free(s), -1);
	}
	if ((s[j] == 0) && (s[j - 1] == ' ' || !ft_isdigit(s[j - 1])))
		return (free(s), -1);
	return (0);
}

int	validate_input(int argc, char **argv)
{
	int		i;
	int		bench;
	char	*comp;
	char	*nbs;

	i = 1;
	bench = 0;
	comp = ft_strdup("--adaptive");
	nbs = ft_strdup("\0");
	if (argc < 2)
		return (free(comp), free(nbs), ft_printf(2, "Error\n"), -1);
	check_flags(argv, &bench, &comp, &i);
	ft_printf(1, "complexity is set to: %s \n", comp);
	if (parse_input(&i, argv, &nbs) == -1)
		return (free (comp), ft_printf(2, "Error in numbers format\n"), -1);
	ft_printf(1, "You parsed them correctly!\n");
	ft_printf(1, "the nbs list entered is: %s\n", nbs);
	free (nbs);
	free (comp);
	return (0);
}
