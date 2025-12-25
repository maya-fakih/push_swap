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
	while (argv[*i] && (*i) <= 2)
	{
		if (ft_streq(argv[*i], "--bench"))
		{
			if (*show_bench == 1)
				return ;
			*show_bench = 1;
			(*i)++;
				
		}
		else if (comp_flag(argv[*i]))
		{
			if (*i == 2 && *show_bench == 0)
				return ;
			free (*complexity);
			*complexity = ft_strdup(argv[*i]);
			(*i)++;
		}
		else
			return ;
	}
}

int	check_input(int *i, char **argv, char **nbs)
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

void	init(int *i, int *bench, char **comp, char **nbs)
{
	*i = 1;
	*bench = 0;
	*comp = ft_strdup("--adaptive");
	*nbs = ft_strdup(" ");
}
