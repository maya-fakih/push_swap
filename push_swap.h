/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitani <mitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 00:04:25 by mfakih            #+#    #+#             */
/*   Updated: 2025/12/30 02:55:46 by mitani           ###   ########.fr       */
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
t_list	*to_list(char *nbs);
void	free_array(char **n);
t_list	*validate(int argc, char **argv, int *bench, char **comp);
t_list	*create_node(int content);
void	print_content(void *content);
int		check_duplicates(t_list	*stack, int value);
void	swap(t_list **stack);
void	push(t_list **lst1, t_list **lst2);
void	rotate(t_list **stack);
void	rev_rotate(t_list **stack);
int		min_value_in_list(t_list *stack, int *index);
void	simple_algorithm(t_list **stack_a, t_list **stack_b, char **operations);
void	complex_algorithm(t_list **stack_a, t_list **stack_b, char **operations);
int		get_ith_bit(int content, int i);

#endif