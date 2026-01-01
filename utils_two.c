/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfakih <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 18:37:19 by mfakih            #+#    #+#             */
/*   Updated: 2025/12/30 18:37:21 by mfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_int_tab(int *array, int len)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	temp = array[i];
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	total_ops(char *ops)
{
	int		i;
	char	**n;

	i = 0;
	n = ft_split((char const *)ops, '\n');
	if (!n)
		return (0);
	while (n[i])
		i++;
	free_array(n);
	return (i);
}

int	c_op(char *ops, char *cmd)
{
	int		i;
	int		count;
	char	**n;

	if (!ops || !cmd)
		return (0);
	n = ft_split((char const *)ops, '\n');
	if (!n)
		return (0);
	i = 0;
	count = 0;
	while (n[i])
	{
		if (ft_streq(n[i], cmd))
			count++;
		i++;
	}
	free_array(n);
	return (count);
}
