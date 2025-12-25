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
