/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfakih <mfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 00:04:25 by mfakih            #+#    #+#             */
/*   Updated: 2025/12/27 18:07:28 by mfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

void	check_flags(char **argv, int *show_bench, char **complexity, int *i);
int		check_input(int *i, char **argv, char **nbs);
void	ft_strjoin_sep(char **s1, char *s2, char *sep);
void	init(int *i, int *bench, char **comp, char **nbs);
int		ft_streq(const char *s, const char *lit);
int		comp_flag(const char *s);
long	ft_atoi_overflow(const char *str, int *overflow);

#endif