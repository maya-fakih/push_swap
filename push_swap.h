/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitani <mitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 00:04:25 by mfakih            #+#    #+#             */
/*   Updated: 2026/01/02 03:21:22 by mitani           ###   ########.fr       */
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
int		get_chunk_count(int stack_size);
int		get_chunk_size(int stack_size);
int		*calculate_chunk_ranges(int stack_size, int *chunk_count);
int		find_element_position(t_list *stack, int rank);
void	push_chunk_to_b(t_list **stack_a, t_list **stack_b, int min_rank,
			int max_rank, char **operations);
int		is_chunk_sorted(t_list *stack_b, int min_rank, int max_rank);
void	rotate_to_chunk_max(t_list **stack_b, int min_rank, int max_rank,
			char **operations);
void	push_chunk_to_a(t_list **stack_a, t_list **stack_b, int min_rank,
			int max_rank, char **operations);
void	medium_algorithm(t_list **stack_a, t_list **stack_b, char **operations);

#endif