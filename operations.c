/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfakih <mfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 22:47:50 by mfakih            #+#    #+#             */
/*   Updated: 2025/12/23 22:47:51 by mfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first -> next;
	first -> next = second->next;
	second -> next = first;
	*stack = second;
}

void	push(t_list **lst1, t_list **lst2)
{
	t_list	*temp;

	if (!lst1 || !*lst1 || !lst2)
		return ;
	temp = *lst1;
	*lst1 = temp -> next;
	temp -> next = NULL;
	ft_lstadd_front(lst2, temp);
}

void	rotate(t_list **stack)
{
	t_list *temp;

	if(!stack || !*stack || !(*stack)-> next)
		return ;
	temp = *stack;
	*stack = temp -> next;
	temp -> next = NULL;
	ft_lstadd_back(stack, temp);
}

void rev_rotate(t_list **stack)
{
	t_list *last;
	t_list *before_last;

	if (!stack || !*stack || !(*stack) -> next)
		return ;
	before_last = *stack;
	last = before_last -> next;
	while (last -> next != NULL)
	{	
		before_last = last;
		last = last -> next;
	}
	before_last -> next = NULL;
	last -> next = *stack;
	*stack = last;
}

