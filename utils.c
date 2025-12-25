/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfakih <mfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 01:36:59 by mfakih            #+#    #+#             */
/*   Updated: 2025/12/25 01:37:01 by mfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_strjoin_sep(char **s1, char *s2, char *sep)
{
	char	*temp;

	if (!s1 || !*s1 || !s2 || !sep)
		return ;
	temp = *s1;
	*s1 = ft_strjoin(*s1, sep);
	if (!s1)
	{
		*s1 = temp;
		return ;
	}
	free (temp);
	temp = *s1;
	*s1 = ft_strjoin(*s1, s2);
	if (!s1)
	{
		*s1 = temp;
		return ;
	}
	free (temp);
}

int	comp_flag(const char *s)
{
	return (ft_streq(s, "--simple")
		|| ft_streq(s, "--medium")
		|| ft_streq(s, "--complex")
		|| ft_streq(s, "--adaptive"));
}

int	ft_streq(const char *s, const char *lit)
{
	if (!s || !lit)
		return (0);
	if (ft_strlen(s) != ft_strlen(lit))
		return (0);
	return (ft_strncmp(s, lit, ft_strlen(lit)) == 0);
}
