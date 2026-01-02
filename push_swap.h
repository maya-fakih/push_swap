/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfakih <mfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 00:04:25 by mfakih            #+#    #+#             */
/*   Updated: 2026/01/02 16:08:50 by mfakih           ###   ########.fr       */
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
void	push_back_to_a(t_list **stack_a, t_list **stack_b, char **operations);
void	simple_algorithm(t_list **stack_a, t_list **stack_b, char **operations);
void	complex_algorithm(t_list **stack_a, t_list **stack_b, char **ops);
int		get_ith_bit(int content, int i);
int		indexx(int value, int *array, int len);
void	rank_stack(t_list **stack_a);
void	sort_int_tab(int *array, int len);
double	compute_disorder(t_list *stack);
void	solve(t_list **a, double d, char **ops, const char *comp);
int		total_ops(char *ops);
int		c_op(char *ops, char *cmd);
int		find_element_position(t_list *stack, int rank);
void	medium_algorithm(t_list **stack_a, t_list **stack_b, char **ops);
int		ft_isqrt(int n);
void	pb(t_list **stack_a, t_list **stack_b, char **ops);
void	pa(t_list **stack_a, t_list **stack_b, char **ops);
void	pb_rb(t_list **stack_a, t_list **stack_b, char **ops);
void	ra(t_list **stack_a, char **ops);
void	rb(t_list **stack_b, char **ops);
void	rrb(t_list **stack_b, char **ops);
void	sort_push_a(t_list **stack_a, t_list **stack_b, char **ops, int n);

#endif