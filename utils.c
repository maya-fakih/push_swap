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

void	ft_strjoin_sep(char **s1, char *s2, char sep)
{
	char	*temp;
	char	*with_sep;
	char	*new_str;

	if (!s1 || !s2)
		return ;
	with_sep = ft_strjoin((char []){sep, '\0'}, s2);
	if (!with_sep)
		return ;
	new_str = ft_strjoin(*s1, with_sep);
	free(with_sep);
	if (!new_str)
		return ;
	temp = *s1;
	*s1 = new_str;
	free(temp);
}
